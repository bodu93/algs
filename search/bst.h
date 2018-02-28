#ifndef BST_H
#define BST_H

#include <cstddef>
#include <utility>
#include <functional>
#include <random>
#include <queue>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

template<typename, typename, typename> class bs_tree;

// binary tree node
template <typename K, typename V>
class node
{
template<typename Key, typename Value, typename Comparer> friend class bs_tree;

public:
	node(const K &k,
			const V &v,
		 	std::size_t s = 1,
			node *l = nullptr,
			node *r = nullptr)
		: key(k), value(v), sb_size(s), left(l), right(r)
	{ }

	K Key() const { return key; }
	V Value() const { return value; }

private:
	K key;
	V value;
	std::size_t sb_size;
	node* left;
	node* right;
};

template<typename Key, typename Value, typename Comparer = std::less<Key>>
class bs_tree
{
public:
	using iterator = node<Key, Value> *;
	using value_type = node<Key, Value>;
	using size_type = std::size_t;
	using traversefunc = std::function<void(iterator)>;

	bs_tree():root(nullptr), compare(Comparer()) { }

	bs_tree(const bs_tree& other)
	: compare(other.compare) {
		using NodePair = std::pair<iterator, iterator>;
		using NodePointer = iterator*;

		NodePointer newnode = &root;
		iterator cur = other.root;
		std::stack<NodePair> nodePairs;
		while (cur || !nodePairs.empty()) {
				// go down most-left-side
				while (cur) {
						// copy node
						iterator copynode = new node<Key, Value>(cur->key, cur->value, cur->sb_size);
						*newnode = copynode;
						// rebind...
						newnode = &(copynode->left);

						if (cur->right) {
								nodePairs.push(std::make_pair(copynode, cur->right));
						}
						cur = cur->left;
				}
				// turn into right sub-tree
				if (!nodePairs.empty()) {
						NodePair np = nodePairs.top();
						nodePairs.pop();
						cur = np.second;
						// rebind...
						newnode = &(np.first->right);
				}
		}
	}

	bs_tree &operator=(const bs_tree &t) {
		bs_tree tmp(t);
		swap(tmp);
		return *this;
	}

	~bs_tree() {
		while (size() != 0)
			delete_min();
	}

	void swap(bs_tree& other) {
		std::swap(root, other.root);
		std::swap(compare, other.compare);
	}

	void preorder_traverse(const traversefunc& traverse) {
		std::stack<iterator> nodes;
		nodes.push(root);

		iterator cur = root;
		while (!nodes.empty()) {
			cur = nodes.top();
			nodes.pop();

			while (cur != nullptr) {
				traverse(cur);
				if (cur->right != nullptr) {
					nodes.push(cur->right);
				}
				cur = cur->left;
			}
		}
	}

	void inorder_traverse(const traversefunc& traverse) {
		std::stack<iterator> nodes;
		iterator cur = root;

		while (cur || !nodes.empty()) {
			while (cur != nullptr) {
				nodes.push(cur);
				cur = cur->left;
			}

			cur = nodes.top();
			nodes.pop();
			traverse(cur);
			cur = cur->right;
		}
	}

	void postorder_traverse(const traversefunc& traverse) {
		// TODO
	}

	void insert(const Key &key, const Value &value) {
		root = insert(root, key, value);
	}

	void erase(const Key &key) {
		root = erase(root, key);
	}

	iterator find(const Key &key) const {
		iterator x = root;
		while (x)
		{
			bool lresult = compare(key, x->key);
			bool rresult = compare(x->key, key);

			if (lresult) x = x->left;
			if (rresult) x = x->right;
			if (!lresult && !rresult) return x;
		}

		return x;
	}

	bool contains(const Key &key) const {
		return find(key) != nullptr;
	}

	bool empty() const { return root == nullptr; }

	size_type size() const { return size(root); }

	iterator min() {
		iterator it = root;
		while (it->left) it = it->left;

		return it;
	}

	iterator max() {
		iterator it = root;
		while (it->right) it = it->right;

		return it;
	}

	iterator floor(const Key &key) {
		iterator ret = nullptr, x = root;
		while (x)
		{
			bool lresult = compare(key, x->key);
			bool rresult = compare(x->key, key);

			if (!lresult && !rresult)	return x;
			else if (lresult)	x = x->left;
			else if (rresult)
			{
				ret = x;
				x = x->right;
			}
		}

		return ret;
	}

	iterator ceil(const Key &key) {
		iterator ret = nullptr, x = root;
		while (x)
		{
			bool lresult = compare(key, x->key);
			bool rresult = compare(x->key, key);

			if (!lresult && !rresult) return x;
			else if (rresult) x = x->right;
			else if (lresult)
			{
				ret = x;
				x = x->left;
			}
		}

		return ret;
	}

	size_type rank(const Key &key) {
		iterator x = root;
		size_type r = 0;

		while (x)
		{
			bool lresult = compare(key, x->key);
			bool rresult = compare(x->key, key);

			if (lresult) x = x->left;
			if (rresult)
			{
				r += 1 + size(x->left);
				x = x->right;
			}
			if (!lresult && !rresult)
			{
				r += size(x->left);
				break;
			}
		}

		return r;
	}

	iterator select(size_type rank) {
		if (rank > size() - 1) return nullptr;
		iterator x = root;
		size_type k = rank;
		while (x)
		{
			size_type t = size(x->left);
			if (t > k)		x = x->left;
			else if (t < k)
			{
				x = x->right;
				k = k - t - 1;
			}
			else return x;
		}

		return x;
	}

	void delete_min() { erase(min()->key); }
	void delete_max() { erase(max()->key); }

	size_type size(const Key &lo, const Key &hi) {
		if (compare(hi, lo))	return 0;

		if (contains(hi))
			return rank(hi) - rank(lo) + 1;
		else
			return rank(hi) - rank(lo);
	}

	void levelTraverse(const traversefunc& traverse) { levelTraverse(root, traverse); }

private:
	iterator insert(iterator r, const Key &key, const Value &val) {
		if (!r) return new node<Key, Value>(key, val);

		bool lresult = compare(key, r->key);
		bool rresult = compare(r->key, key);

		if (rresult) 	r->right = insert(r->right, key, val);
		if (lresult)	r->left = insert(r->left, key, val);
		if (!lresult && !rresult) r->value = val;

		r->sb_size = size(r->left) + size(r->right) + 1;

		return r;
	}

	iterator erase(iterator r, const Key &key) {
		if (!r) return nullptr;
		bool lresult = compare(key, r->key);
		bool rresult = compare(r->key, key);

		if (rresult)	r->right = erase(r->right, key);
		if (lresult)		r->left = erase(r->left, key);
		if (!lresult && !rresult) {
			if (r->left && r->right) {
				// flipping a coin
				iterator tmp = r;
				if (flippingCoin()) {
					r = max(r->left);
					r->left = erase(r->left, r->key);
					r->right = tmp->right;
				}
				else {
					r = min(r->right);
					r->right = erase(r->right, r->key);
					r->left = tmp->left;
				}
			}
			else {
				iterator tmpcell = r;
				if (r->left) r = r->left;
				else if (r->right) r = r->right;
				else // r->left == nullptr && r->right == nullptr
					r = nullptr;
				delete tmpcell;
				return r;
			}
		}
		r->sb_size = size(r->left) + size(r->right) + 1;

		return r;
	}

	void levelTraverse(iterator x, const traversefunc& traverse) {
		std::queue<iterator> q;
		q.push(x);

		while (!q.empty())
		{
			iterator x = q.front();
			q.pop();
			// std::cout << x->key << ": " << x->value << std::endl;
			traverse(x);
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}
	}

	iterator min(iterator r) {
		iterator it = r;
		while (it->left) it = it->left;

		return it;
	}

	iterator max(iterator r) {
		iterator it = r;
		while (it->right) it = it->right;

		return it;
	}

	bool flippingCoin() {
		static std::default_random_engine e;
		static std::uniform_real_distribution<double> u(0, 1);

		return u(e) <= 0.500;
	}

	size_type size(iterator r) const {
		if(!r) return 0;
		return r->sb_size;
	}

	iterator root;
	Comparer compare;
};

template class bs_tree<char, std::string>;

#endif

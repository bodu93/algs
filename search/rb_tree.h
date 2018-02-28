#ifndef TOY_RB_TREE_H
#define TOY_RB_TREE_H

#include <functional>
#include <stddef.h>
#include <queue>
#include <stack>
#include <utility> // std::swap since C++11

#include <iostream>

template<typename, typename, typename> class rb_tree;

template<typename K, typename V>
class rb_node {
	template<typename Key, typename Value, typename Comparer> friend class rb_tree;

public:
	using Color = enum class Color{ Red, Black };

	explicit rb_node(
		const K &k,
		const V &v,
		Color c = Color::Red,
		rb_node *l = nullptr,
		rb_node *r = nullptr)
		: key(k), value(v), color(c), left(l), right(r)
	{ }

	K Key() const { return key; }
	V Value() const { return value; }

	~rb_node() { left = right = nullptr; }

private:
	K key;
	V value;

	rb_node *left = nullptr;
	rb_node *right = nullptr;
	Color color = Color::Red;
};

template<typename Key, typename Value, typename Comparer = std::less<Key>>
class rb_tree {
public:
	using iterator = rb_node<Key, Value> *;
	using Color = typename rb_node<Key, Value>::Color;

	rb_tree():root_(nullptr), keyComparer_(Comparer()) { }

	// copy tree: using inorder traverse
	rb_tree(const rb_tree& other) {
		using NodePair = std::pair<iterator, iterator>;
		using NodePointer = iterator*;

		NodePointer newnode = &root_;
		iterator cur = other.root_;
		std::stack<NodePair> nodePairs;
		while (cur || !nodePairs.empty()) {
				// go down most-left-side
				while (cur) {
						// copy node
						iterator copynode = new rb_node<Key, Value>(cur->key, cur->value, cur->color);
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

		keyComparer_ = other.keyComparer_;
	}

	// exception-safe implementation
	rb_tree& operator=(const rb_tree& other) {
		rb_tree tmp(other);
		swap(tmp);
		return *this;
	}

	~rb_tree() {
		while (root_ && (root_->left || root_->right))
			deleteMin(root_);
		deleteMin(root_);
	}

	void swap(rb_tree& other) {
		std::swap(root_, other.root_);
		std::swap(keyComparer_, other.keyComparer_);
	}

	void insert(const Key &key, const Value &value) {
		root_ = insert(root_, key, value);
		root_->color = Color::Black;
	}

	void erase(const Key &key) {
		if (!isRed(root_->left) && !isRed(root_->right))
			root_->color = Color::Red;
		root_ = erase(root_, key);
		if (!isEmpty()) root_->color = Color::Black;
	}

	bool isEmpty() {
		return !(root_->left && root_->right);
	}

	// for debug
	void LevelPrint() {
		std::cout << ".....LevelPrinting....." << std::endl;
		iterator x = root_;
		std::queue<iterator> nodes;
		nodes.push(x);
		while (!nodes.empty())
		{
			iterator cur = nodes.front();
			std::cout << cur->key << ": " << cur->value << " ";
			std::cout << ((cur->color == Color::Red) ? "red" : "black")
					  << std::endl;
			nodes.pop();
			if (cur->left) nodes.push(cur->left);
			if (cur->right) nodes.push(cur->right);
		}
		std::cout << ".....LevelPrinting....." <<std::endl;
	}

	iterator find(const Key &key) {
		iterator h = root_;
		while (h)
		{
			int result = compareTo(key, h->key);
			if (!result)	return h;
			else if (result < 0) h = h->left;
			else h = h->right;
		}
		return h;
	}

private:
	// modify iterator, so use
	// iterator& !!!
	iterator insert(iterator &h, const Key &key, const Value &value) {
		if (!h) return new rb_node<Key, Value>(key, value);

		bool lresult = keyComparer_(key, h->key);
		bool rresult = keyComparer_(h->key, key);

		if (lresult)	h->left = insert(h->left, key, value);
		if (rresult)	h->right = insert(h->right, key, value);
		if (!lresult && !rresult)	h->value = value;

		if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
		if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
		if (isRed(h->left) && isRed(h->right)) flipColor(h);

		return h;
	}

	iterator moveRedLeft(iterator &h) {
		colorFlip(h);
		if (isRed(h->right->left))
		{
			h->right = rotateRight(h->right);
			h = rotateLeft(h);
			colorFlip(h);
		}
		return h;
	}

	iterator moveRedRight(iterator &h) {
		colorFlip(h);
		if (isRed(h->left->left))
		{
			h = rotateRight(h);
			colorFlip(h);
		}
		return h;
	}

	iterator fixUp(iterator &h) {
		if (isRed(h->right))
			h = rotateLeft(h);
		if (isRed(h->left) && isRed(h->left->left))
			h = rotateRight(h);
		if (isRed(h->left) && isRed(h->right))
			flipColor(h);

		return h;
	}

	inline
	int compareTo(const Key &l, const Key &r) {
		int result = 0;
		bool lresult = keyComparer_(l, r);
		bool rresult = keyComparer_(r, l);
		if (lresult) result = -1;
		if (rresult) result = 1;
		return result;
	}

	iterator erase(iterator &h, const Key &key) {
		if (compareTo(key, h->key) < 0)
		{
			if (!isRed(h->left) && !isRed(h->left->left))
				h = moveRedLeft(h);
			h->left = erase(h->left, key);
		}
		else
		{
			if (isRed(h->left))
				h = rotateRight(h);
			if (!keyComparer_(key, h->key) && !(h->right))
			{
				// do remove
				delete h;
				return nullptr;
			}
			if (!isRed(h->right) && !isRed(h->right->left))
			{
				h = moveRedRight(h);
			}
			if (!keyComparer_(key, h->key))
			{
				iterator m = findMin(h->right);
				h->key = m->key;
				h->value = m->value;
				h->right = deleteMin(h->right);
			}
			else
				h->right = erase(h->right, key);
		}
		return fixUp(h);
	}

	iterator deleteMax(iterator &h) {
		if (isRed(h->left))
			h = rotateRight(h);
		if (!(h->right))
		{
			delete h;
			return nullptr;
		}
		if (!isRed(h->right) && !isRed(h->right->left))
			h = moveRedRight(h);
		h->right = deleteMax(h->right);

		return fixUp(h);
	}

	iterator deleteMin(iterator &h) {
 		if (!(h->left))
		{
			delete h;
			return nullptr;
		}
		if (!isRed(h->left) && !isRed(h->left->left))
			h = moveRedLeft(h);
		h->left = deleteMin(h->left);

		return fixUp(h);
	}

	iterator findMin(iterator h) {
		iterator x = h;
		while (x->left)	x = x->left;
		return x;
	}

	bool isRed(iterator h) const {
		if (!h) return false;
		return h->color == Color::Red;
	}

	bool isRed(iterator h) {
		return const_cast<const rb_tree*>(this)->isRed(h);
	}

	iterator rotateLeft(iterator &h) {
		iterator x = h->right;
		h->right = x->left;
		x->left = h;
		x->color = h->color;
		h->color = Color::Red;
		return x;
	}

	iterator rotateRight(iterator &h) {
		iterator x = h->left;
		h->left = x->right;
		x->right = h;
		x->color = h->color;
		h->color = Color::Red;
		return x;
	}

	void flipColor(iterator &h) {
		h->color = Color::Red;
		h->left->color = Color::Black;
		h->right->color = Color::Black;
	}

	void colorFlip(iterator &h) {
		h->color = Color::Black;
		h->left->color = Color::Red;
		h->right->color = Color::Red;
	}

	iterator root_;
	Comparer keyComparer_;
};

template<typename Key, typename Value, typename Comparer>
void swap(rb_tree<Key, Value, Comparer>& l, rb_tree<Key, Value, Comparer>& r) {
	l.swap(r);
}

// explicit instantiation
// extern template class rb_tree<int, char>;

#endif // TOY_RB_TREE_H

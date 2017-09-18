class Node;

Node rotateLeft(Node h) {
    Node x = h.right;
    h.right = x.left;
    x.left = h;
    x.color = x.left.color;
    x.left.color = RED;
    return x;
}

Node rotateRight(Node h) {
    Node x = h.left;
    h.left = x.right;
    x.right = h;
    x.color = x.right.color;
    x.right.color = RED;
    return x;
}

Node colorFlip(Node h) {
    x.color = !x.color;
    x.left.color = !x.left.color;
    x.right.color = !x.right.color;
    return x;
}


// insert strategy:
// invariant: current node is not a 4-node
Node insert(Node h, Key key, Value val) {
    if (h == null) {
        return new Node(key, val, RED);
    }

    // top-down 2-3-4 tree insert
    if (isRed(h.left) && isRed(h.right)) {
        colorFlip(h);
    }

    int cmp = key.compareTo(h.key);
    if (cmp == 0) h.val = val;
    else if (cmp < 0)
        h.left = insert(h.left, key, val);
    else
        h.right = insert(h.right, key, val);

    if (isRed(h.right))
        h = rotateLeft(h);

    if (isRed(h.left) && isRed(h.left.left))
        h = rotateRight(h);

    // bottom-up 2-3 tree insert
    if (isRed(h.left) && isRed(h.right)) {
        colorFlip(h);
    }

    return h;
}

Node fixUp(Node h) {
    if (isRed(h.right))
        h = rotateLeft(h);
    if (isRed(h.left) && isRed(h.left.left))
        h = rotateRight(h);
    if (isRed(h.left) && isRed(h.right))
        colorFlip(h);

    return h;
}


// delete strategy:
// invariant: current node is not a 2-node
Node moveRedRight(Node h) {
    colorFlip(h);
    if (isRed(h.left.left)) {
        h = rotateRight(h);
        colorFlip(h);
    }

    return h;
}

void deleteMax() {
    root = deleteMax(root);
    root.color = BLACK;
}

Node deleteMax(Node h) {
    if (isRed(h.left))
        h = rotateRight(h);

    if (h.right == null)
        return null;

    if (!isRed(h.right) && !isRed(h.right.left))
        h = moveRedRight(h);

    h.left = deleteMax(h.left);

    return fixUp(h);
}

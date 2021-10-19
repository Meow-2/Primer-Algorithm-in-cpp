#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
template <typename Key, typename Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };
    Node *root;
    int count;

public:
    BST() : root(nullptr), count(0) {}
    ~BST()
    {
        //TODO:~BST(){}
    }
    bool isEmpty()
    {
        return count == 0;
    }
    int size()
    {
        return count;
    }
    void insert(Key key, Value value);
    Node *insertNode(Node *node, Key key, Value value);
    void insertCycle(Key key, Value value);
};

template <typename Key, typename Value>
BST<Key, Value>::Node *BST<Key, Value>::insertNode(Node *node, Key key, Value value)
{
    //node为根节点，nodeI为要插入的节点,返回值为插入的树的根
    if (node == nullptr)
    {
        return new Node(key, value);
    }
    else if (node->key == key)
    {
        node->value = value;
        return node;
    }
    else if (node->key < key)
    {
        node->right = insertNode(node->right, key, value);
    }
    else
        node->left = insertNode(node->left, key, value);
    return node;
}

template <typename Key, typename Value>
void BST<Key, Value>::insert(Key key, Value value)
{
    root = insertNode(root, key, value);
}

template <typename Key, typename Value>
void BST<Key, Value>::insertCycle(Key key, Value value)
{
    if (root == nullptr)
    {
        root = new Node(key, value);
        return;
    }
    Node *node = root;
    Node *nodeLast = root;
    while (node != nullptr)
    {
        if (node->key == key)
        {
            node->value = value;
            return;
        }
        else if (node->key < key)
        {
            nodeLast = node;
            node = node->right;
        }
        else
        {
            nodeLast = node;
            node = node->left;
        }
    }
    if (nodeLast->key < key)
    {
        nodeLast->right = new Node(key, value);
    }
    else
        nodeLast->left = new Node(key, value);
}
#endif
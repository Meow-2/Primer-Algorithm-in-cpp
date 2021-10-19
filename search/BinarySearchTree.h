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
    void insertNode(Node *&nodeR, Node *&nodeI)
    {
        //nodeR为根节点，nodeI为要插入的节点
        if (nodeR == nullptr)
        {
            nodeR = nodeI;
            return;
        }
        else if (nodeR->key <= nodeI->key)
        {
            insertNode(nodeR->right, nodeI);
        }
        else
            insertNode(nodeR->left, nodeI);
        return;
    }
};

template <typename Key, typename Value>
void BST<Key, Value>::insert(Key key, Value value)
{
    //nodeN新节点
    Node *nodeN = new Node(key, value);
    insertNode(root, nodeN);
    return;
}
#endif
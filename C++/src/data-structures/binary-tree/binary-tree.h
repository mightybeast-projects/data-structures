using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
};

template <typename T>
class BinaryTree
{
public:
    Node<T> *root;

    vector<T> preOrderTraversal()
    {
        return preOrderRecurse(root, vector<int>{});
    }

private:
    vector<T> preOrderRecurse(Node<T> *node, vector<T> arr)
    {
        arr.push_back(node->value);

        if (node->left != nullptr)
            preOrderRecurse(node->left, arr);
        if (node->right != nullptr)
            preOrderRecurse(node->right, arr);

        return arr;
    }
};
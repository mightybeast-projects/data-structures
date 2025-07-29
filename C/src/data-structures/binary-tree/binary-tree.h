typedef struct binaryTreeNode BinaryTreeNode;

struct binaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* createBinaryTreeNode(int value);
int* preOrderTraverse(const BinaryTreeNode* root);
int* inOrderTraverse(const BinaryTreeNode* root);
void deleteBinaryTreeNode(BinaryTreeNode* node);
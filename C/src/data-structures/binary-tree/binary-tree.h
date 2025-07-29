typedef struct binaryTreeNode BinaryTreeNode;

struct binaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* createBinaryTreeNode(int value);
void deleteBinaryTreeNode(BinaryTreeNode* node);
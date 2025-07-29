#include "binary-tree.h"
#include "stdlib.h"

static void traverse(const BinaryTreeNode* node, int* res, int* index);

BinaryTreeNode* createBinaryTreeNode(int value)
{
    BinaryTreeNode* node = malloc(sizeof(struct binaryTreeNode));

    if (!node)
        return NULL;

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int* preOrderTraverse(const BinaryTreeNode* root)
{
    int* res = malloc(sizeof(int) * 10);
    int index = 0;

    traverse(root, res, &index);

    return res;
}

static void traverse(const BinaryTreeNode* node, int* res, int* index)
{
    res[(*index)++] = node->value;

    if (node->left)
        traverse(node->left, res, index);

    if (node->right)
        traverse(node->right, res, index);
}

void deleteBinaryTreeNode(BinaryTreeNode* node)
{
    if (!node)
        return;

    if (node->left)
        deleteBinaryTreeNode(node->left);

    if (node->right)
        deleteBinaryTreeNode(node->right);

    free(node);
}
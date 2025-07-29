#include "binary-tree.h"
#include "stdlib.h"

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
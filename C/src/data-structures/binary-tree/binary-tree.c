#include "binary-tree.h"
#include "stdlib.h"

static void traversePre(const BinaryTreeNode* node, int* res, int* index);
static void traverseIn(const BinaryTreeNode* node, int* res, int* index);
static void traversePost(const BinaryTreeNode* node, int* res, int* index);

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

    traversePre(root, res, &index);

    return res;
}

int* inOrderTraverse(const BinaryTreeNode* root)
{
    int* res = malloc(sizeof(int) * 10);
    int index = 0;

    traverseIn(root, res, &index);

    return res;
}

int* postOrderTraverse(const BinaryTreeNode* root)
{
    int* res = malloc(sizeof(int) * 10);
    int index = 0;

    traversePost(root, res, &index);

    return res;
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

static void traversePre(const BinaryTreeNode* node, int* res, int* index)
{
    res[(*index)++] = node->value;

    if (node->left)
        traversePre(node->left, res, index);

    if (node->right)
        traversePre(node->right, res, index);
}

static void traverseIn(const BinaryTreeNode* node, int* res, int* index)
{
    if (node->left)
        traverseIn(node->left, res, index);

    res[(*index)++] = node->value;

    if (node->right)
        traverseIn(node->right, res, index);
}

static void traversePost(const BinaryTreeNode* node, int* res, int* index)
{
    if (node->left)
        traversePost(node->left, res, index);

    if (node->right)
        traversePost(node->right, res, index);

    res[(*index)++] = node->value;
}
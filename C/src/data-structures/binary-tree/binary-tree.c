#define QUEUE_ITEM_TYPE const BinaryTreeNode*
#include "binary-tree.h"
#include "../queue/queue.h"
#include "stdlib.h"

static int* prepareTraverse(
    const BinaryTreeNode* node,
    void func(const BinaryTreeNode* node, int* res, int* index));

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
    return prepareTraverse(root, traversePre);
}

int* inOrderTraverse(const BinaryTreeNode* root)
{
    return prepareTraverse(root, traverseIn);
}

int* postOrderTraverse(const BinaryTreeNode* root)
{
    return prepareTraverse(root, traversePost);
}

int* bfs(const BinaryTreeNode* node)
{
    int* res = malloc(sizeof(int) * 10);
    int index = 0;
    Queue* queue = createQueue();

    queueEnqueue(queue, node);

    while (queuePeek(queue))
    {
        const BinaryTreeNode* n = queueDequeue(queue);

        if (n->left)
            queueEnqueue(queue, n->left);

        if (n->right)
            queueEnqueue(queue, n->right);

        res[index++] = n->value;
    }

    deleteQueue(queue);

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

static int* prepareTraverse(
    const BinaryTreeNode* node,
    void func(const BinaryTreeNode* node, int* res, int* index))
{
    int* res = malloc(sizeof(int) * 10);
    int index = 0;

    func(node, res, &index);

    return res;
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
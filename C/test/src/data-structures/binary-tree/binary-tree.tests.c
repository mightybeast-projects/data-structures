#include "binary-tree.tests.h"
#include "binary-tree.h"
#include "unity.h"

BinaryTreeNode* root;

void setUpBinaryTree(void)
{
    root = createBinaryTreeNode(1);
    root->left = createBinaryTreeNode(2);
    root->right = createBinaryTreeNode(3);
    root->left->left = createBinaryTreeNode(4);
    root->left->right = createBinaryTreeNode(5);
    root->right->left = createBinaryTreeNode(6);
}

void tearDownBinaryTree(void)
{
    deleteBinaryTreeNode(root);
}

void Binary_Tree_Node_Create_Should_Return_Newly_Created_Node(void)
{
    TEST_ASSERT_NOT_NULL(root);
    TEST_ASSERT_NOT_NULL(root->left);
    TEST_ASSERT_NOT_NULL(root->right);
    TEST_ASSERT_NOT_NULL(root->left->left);
    TEST_ASSERT_NOT_NULL(root->left->right);
    TEST_ASSERT_NOT_NULL(root->right->left);
}

void runBinaryTreeTests(void)
{
    RUN_TEST(Binary_Tree_Node_Create_Should_Return_Newly_Created_Node);
}

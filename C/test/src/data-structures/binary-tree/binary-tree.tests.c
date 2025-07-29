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

void Binary_Tree_Pre_Order_Traverse_Should_Start_With_Root_Node(void)
{
    int* actual = preOrderTraverse(root);
    int expected[6] = { 1, 2, 4, 5, 3, 6 };

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 6);
}

void Binary_Tree_In_Order_Traverse_Should_Start_With_Leftmost_Node(void)
{
    int* actual = inOrderTraverse(root);
    int expected[6] = { 4, 2, 5, 1, 6, 3 };

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 6);
}

void Binary_Tree_Post_Order_Traverse_Should_Start_With_Children_Nodes(void)
{
    int* actual = postOrderTraverse(root);
    int expected[6] = { 4, 5, 2, 6, 3, 1 };

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 6);
}

void runBinaryTreeTests(void)
{
    RUN_TEST(Binary_Tree_Node_Create_Should_Return_Newly_Created_Node);
    RUN_TEST(Binary_Tree_Pre_Order_Traverse_Should_Start_With_Root_Node);
    RUN_TEST(Binary_Tree_In_Order_Traverse_Should_Start_With_Leftmost_Node);
    RUN_TEST(Binary_Tree_Post_Order_Traverse_Should_Start_With_Children_Nodes);
}

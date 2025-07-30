#include "binary-tree.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

class Binary_Tree : public testing::Test
{
public:
    binaryTree::BinaryTree<int> tree;

    void SetUp() override
    {
        tree.root = buildRoot();
    }

    void TearDown() override
    {
        deleteNode(tree.root);

        tree.root = nullptr;
    }

private:
    binaryTree::Node<int>* buildRoot()
    {
        auto n4 = new binaryTree::Node<int> { 4 };
        auto n5 = new binaryTree::Node<int> { 5 };

        auto n6 = new binaryTree::Node<int> { 6 };
        auto n7 = new binaryTree::Node<int> { 7 };

        auto n2 = new binaryTree::Node<int> { 2, n4, n5 };
        auto n3 = new binaryTree::Node<int> { 3, n6, n7 };

        return new binaryTree::Node<int> { 1, n2, n3 };
    }

    void deleteNode(binaryTree::Node<int>* node)
    {
        if (!node)
            return;

        auto left = node->left;
        auto right = node->right;

        deleteNode(left);
        deleteNode(right);

        delete node;
    }
};

TEST_F(Binary_Tree, Tree_Is_Traversable_Pre_Order)
{
    testingUtils::EXPECT_EQ_VEC(
        tree.btPreOrderTraversal(), std::vector<int> { 1, 2, 4, 5, 3, 6, 7 });
}

TEST_F(Binary_Tree, Tree_Is_Traversable_In_Order)
{
    testingUtils::EXPECT_EQ_VEC(
        tree.btInOrderTraversal(), std::vector<int> { 4, 2, 5, 1, 6, 3, 7 });
}

TEST_F(Binary_Tree, Tree_Is_Traversable_Post_Order)
{
    testingUtils::EXPECT_EQ_VEC(
        tree.btPostOrderTraversal(), std::vector<int> { 4, 5, 2, 6, 7, 3, 1 });
}
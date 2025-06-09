#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "bt-bfs.hpp"

namespace BTBFS
{
    using namespace TestingUtils;

    class BTFSTests : public testing::Test
    {
    protected:
        BinaryTree::BinaryTree<int> tree;

        void SetUp() override
        {
            tree.root = new BinaryTreeNode::Node<int>{
                1,
                new BinaryTreeNode::Node<int>{
                    2,
                    new BinaryTreeNode::Node<int>{
                        4,
                        nullptr,
                        nullptr},
                    new BinaryTreeNode::Node<int>{
                        5,
                        nullptr,
                        nullptr}},
                new BinaryTreeNode::Node<int>{
                    3,
                    new BinaryTreeNode::Node<int>{
                        6,
                        nullptr,
                        nullptr},
                    new BinaryTreeNode::Node<int>{
                        7,
                        nullptr,
                        nullptr}}};
        }
    };

    TEST_F(BTFSTests, BTBFS_IsCorrect)
    {
        EXPECT_TRUE(btBFS(tree, 3));
        EXPECT_TRUE(btBFS(tree, 7));
        EXPECT_FALSE(btBFS(tree, -1));
    }
}
#include <gtest/gtest.h>
#include "testing-utils.h"
#include "bt-dfs.h"

namespace BTDFS
{
    using namespace TestingUtils;

    class BTDFSTests : public testing::Test
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

    TEST_F(BTDFSTests, BTDFS_IsCorrect)
    {
        EXPECT_TRUE(btDFS(tree, 3));
        EXPECT_TRUE(btDFS(tree, 7));
        EXPECT_FALSE(btDFS(tree, -1));
    }
}
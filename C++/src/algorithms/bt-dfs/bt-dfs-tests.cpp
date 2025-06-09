#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "bt-dfs.hpp"

namespace btdfs
{
    using namespace testingUtils;

    class BTDFSTests : public testing::Test
    {
    protected:
        binaryTree::BinaryTree<int> tree;

        void SetUp() override
        {
            tree.root = new binaryTreeNode::Node<int>{
                1,
                new binaryTreeNode::Node<int>{
                    2,
                    new binaryTreeNode::Node<int>{
                        4,
                        nullptr,
                        nullptr},
                    new binaryTreeNode::Node<int>{
                        5,
                        nullptr,
                        nullptr}},
                new binaryTreeNode::Node<int>{
                    3,
                    new binaryTreeNode::Node<int>{
                        6,
                        nullptr,
                        nullptr},
                    new binaryTreeNode::Node<int>{
                        7,
                        nullptr,
                        nullptr}}};
        }
    };

    TEST_F(BTDFSTests, BTDFS_IsCorrect)
    {
        EXPECT_TRUE(btdfs(tree, 3));
        EXPECT_TRUE(btdfs(tree, 7));
        EXPECT_FALSE(btdfs(tree, -1));
    }
}
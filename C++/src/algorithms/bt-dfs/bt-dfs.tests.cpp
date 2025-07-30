#include "bt-dfs.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(BTDFS, Node_Is_Found)
{
    binaryTree::Node<int> n4 { 4 };
    binaryTree::Node<int> n5 { 5 };
    binaryTree::Node<int> n6 { 6 };
    binaryTree::Node<int> n7 { 7 };

    binaryTree::Node<int> n2 { 2, &n4, &n5 };
    binaryTree::Node<int> n3 { 3, &n6, &n7 };
    binaryTree::Node<int> root { 1, &n2, &n3 };

    binaryTree::BinaryTree<int> tree;
    tree.root = &root;

    btDFS::BTDFS<int> dfs;

    EXPECT_TRUE(dfs.btdfs(tree, 3));
    EXPECT_TRUE(dfs.btdfs(tree, 7));
    EXPECT_FALSE(dfs.btdfs(tree, -1));
}
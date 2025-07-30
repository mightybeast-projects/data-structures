#include "bt-bfs.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(BTBFS, Node_Is_Found)
{
    binaryTree::BinaryTree<int> tree;

    binaryTree::Node<int> n4 { 4 };
    binaryTree::Node<int> n5 { 5 };
    binaryTree::Node<int> n6 { 6 };
    binaryTree::Node<int> n7 { 7 };

    binaryTree::Node<int> n2 { 2, &n4, &n5 };
    binaryTree::Node<int> n3 { 3, &n6, &n7 };
    binaryTree::Node<int> root { 1, &n2, &n3 };

    tree.root = &root;

    EXPECT_TRUE(btBFS::btbfs(tree, 3));
    EXPECT_TRUE(btBFS::btbfs(tree, 7));
    EXPECT_FALSE(btBFS::btbfs(tree, -1));
}
#include "bt-bfs.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

using namespace testingUtils;
using namespace binaryTree;
using namespace btBFS;

TEST(BTBFS, Node_Is_Found)
{
    BinaryTree<int> tree;

    Node<int> n4 { 4, nullptr, nullptr };
    Node<int> n5 { 5, nullptr, nullptr };
    Node<int> n6 { 6, nullptr, nullptr };
    Node<int> n7 { 7, nullptr, nullptr };

    Node<int> n2 { 2, &n4, &n5 };
    Node<int> n3 { 3, &n6, &n7 };
    Node<int> root { 1, &n2, &n3 };

    tree.root = &root;

    EXPECT_TRUE(btbfs(tree, 3));
    EXPECT_TRUE(btbfs(tree, 7));
    EXPECT_FALSE(btbfs(tree, -1));
}
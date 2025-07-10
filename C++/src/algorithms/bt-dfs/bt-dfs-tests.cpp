#include "bt-dfs.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

using namespace btDFS;
using namespace testingUtils;
using namespace binaryTree;

TEST(BTDFS, Node_Is_Found)
{
    Node<int> n4 { 4, nullptr, nullptr };
    Node<int> n5 { 5, nullptr, nullptr };
    Node<int> n6 { 6, nullptr, nullptr };
    Node<int> n7 { 7, nullptr, nullptr };

    Node<int> n2 { 2, &n4, &n5 };
    Node<int> n3 { 3, &n6, &n7 };
    Node<int> root { 1, &n2, &n3 };

    BinaryTree<int> tree;
    tree.root = &root;

    BTDFS<int> dfs;

    EXPECT_TRUE(dfs.btdfs(tree, 3));
    EXPECT_TRUE(dfs.btdfs(tree, 7));
    EXPECT_FALSE(dfs.btdfs(tree, -1));
}
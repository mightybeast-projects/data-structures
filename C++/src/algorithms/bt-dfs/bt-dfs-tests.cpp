#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "bt-dfs.hpp"

using namespace btDFS;
using namespace testingUtils;
using namespace binaryTree;

TEST(BTDFS, Node_Is_Found)
{
    BinaryTree<int> tree;

    tree.root = new Node<int>{
        1,
        new Node<int>{
            2,
            new Node<int>{
                4,
                nullptr,
                nullptr},
            new Node<int>{
                5,
                nullptr,
                nullptr}},
        new Node<int>{
            3,
            new Node<int>{
                6,
                nullptr,
                nullptr},
            new Node<int>{
                7,
                nullptr,
                nullptr}}};

    BTDFS<int> dfs;

    EXPECT_TRUE(dfs.btdfs(tree, 3));
    EXPECT_TRUE(dfs.btdfs(tree, 7));
    EXPECT_FALSE(dfs.btdfs(tree, -1));
}
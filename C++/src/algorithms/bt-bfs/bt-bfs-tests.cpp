#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "bt-bfs.hpp"

using namespace testingUtils;
using namespace binaryTree;
using namespace btBFS;

TEST(BTBFS, Node_Is_Found)
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

    EXPECT_TRUE(btbfs(tree, 3));
    EXPECT_TRUE(btbfs(tree, 7));
    EXPECT_FALSE(btbfs(tree, -1));
}
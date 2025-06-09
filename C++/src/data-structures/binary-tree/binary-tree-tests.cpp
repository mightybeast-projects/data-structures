#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "binary-tree.hpp"

namespace BinaryTree
{
    using namespace std;
    using namespace TestingUtils;
    using namespace BinaryTreeNode;

    class BinaryTreeTests : public testing::Test
    {
    protected:
        BinaryTree<int> tree;

        void SetUp() override
        {
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
        }
    };

    TEST_F(BinaryTreeTests, PreOrderTraversal_IsCorrect)
    {
        EXPECT_EQ_VEC(tree.btPreOrderTraversal(), vector<int>{1, 2, 4, 5, 3, 6, 7});
    }

    TEST_F(BinaryTreeTests, InOrderTraversal_IsCorrect)
    {
        EXPECT_EQ_VEC(tree.btInOrderTraversal(), vector<int>{4, 2, 5, 1, 6, 3, 7});
    }

    TEST_F(BinaryTreeTests, PostOrderTraversal_IsCorrect)
    {
        EXPECT_EQ_VEC(tree.btPostOrderTraversal(), vector<int>{4, 5, 2, 6, 7, 3, 1});
    }
}
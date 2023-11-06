#include <gtest/gtest.h>
#include "testing-utils.h"
#include "binary-tree.h"

using namespace std;
using namespace TestingUtils;

class BinaryTreeTests : public testing::Test
{
public:
    BinaryTree<int> tree;

protected:
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
    EXPECT_EQ_VEC(tree.preOrderTraversal(), vector<int>{1, 2, 4, 5, 3, 6, 7});
}
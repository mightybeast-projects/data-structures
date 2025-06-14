#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "binary-tree.hpp"

using namespace std;
using namespace testing;
using namespace testingUtils;
using namespace binaryTree;

class Binary_Tree : public Test
{
public:
    BinaryTree<int> tree;

    void SetUp() override
    {
        tree.root = buildRoot();
    }

    void TearDown() override
    {
        deleteNode(tree.root);

        tree.root = nullptr;
    }

private:
    Node<int> *buildRoot()
    {
        auto n4 = new Node<int>{4};
        auto n5 = new Node<int>{5};

        auto n6 = new Node<int>{6};
        auto n7 = new Node<int>{7};

        auto n2 = new Node<int>{2, n4, n5};
        auto n3 = new Node<int>{3, n6, n7};

        return new Node<int>{1, n2, n3};
    }

    void deleteNode(Node<int> *node)
    {
        if (!node)
            return;

        auto left = node->left;
        auto right = node->right;

        deleteNode(left);
        deleteNode(right);

        delete node;
    }
};

TEST_F(Binary_Tree, Tree_Is_Traversable_Pre_Order)
{
    EXPECT_EQ_VEC(tree.btPreOrderTraversal(), vector<int>{1, 2, 4, 5, 3, 6, 7});
}

TEST_F(Binary_Tree, Tree_Is_Traversable_In_Order)
{
    EXPECT_EQ_VEC(tree.btInOrderTraversal(), vector<int>{4, 2, 5, 1, 6, 3, 7});
}

TEST_F(Binary_Tree, Tree_Is_Traversable_Post_Order)
{
    EXPECT_EQ_VEC(tree.btPostOrderTraversal(), vector<int>{4, 5, 2, 6, 7, 3, 1});
}
#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "bt-bfs.hpp"

namespace btBFS
{
    using namespace testing;
    using namespace testingUtils;
    using namespace binaryTree;

    class BTBFS : public Test
    {
    protected:
        BinaryTree<int> tree;

        void SetUp() override
        {
            tree.root = buildRoot();
        }

    private:
        Node<int> *buildRoot()
        {
            return new Node<int>{
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

    TEST_F(BTBFS, Node_Is_Found)
    {
        EXPECT_TRUE(btbfs(tree, 3));
        EXPECT_TRUE(btbfs(tree, 7));
        EXPECT_FALSE(btbfs(tree, -1));
    }
}
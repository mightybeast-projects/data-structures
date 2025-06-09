#include <gtest/gtest.h>
#include "testing-utils.hpp"
#include "bt-dfs.hpp"

namespace btdfs
{
    using namespace testing;
    using namespace testingUtils;
    using namespace binaryTree;

    class BTDFSTests : public Test
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

    TEST_F(BTDFSTests, BTDFS_IsCorrect)
    {
        EXPECT_TRUE(btdfs(tree, 3));
        EXPECT_TRUE(btdfs(tree, 7));
        EXPECT_FALSE(btdfs(tree, -1));
    }
}
#include <gtest/gtest.h>
#include "testing-utils.h"
#include "linked-list.h"
#include "linked-list-node.h"

namespace LinkedList
{
    using namespace TestingUtils;
    using namespace LinkedListNode;

    void EXPECT_NULL_LINKEDLIST(LinkedList<int> list);

    TEST(LinkedListTests, LinkedList_IsCorrect)
    {
        LinkedList<int> list;

        EXPECT_NULL_LINKEDLIST(list);

        list.append(3);

        EXPECT_EQ(list.length, 1);
        EXPECT_EQ(list.head, list.tail);
        EXPECT_EQ(list.head->value, 3);

        list.append(5);
        list.append(7);

        EXPECT_EQ(list.length, 3);
        EXPECT_NE(list.head, list.tail);
        EXPECT_EQ(list.head->value, 3);
        EXPECT_EQ(list.head->next->value, 5);
        EXPECT_EQ(list.tail->prev->value, 5);
        EXPECT_EQ(list.tail->value, 7);

        EXPECT_NULL(list.get(-1));
        EXPECT_NULL(list.get(3));
        EXPECT_EQ(list.get(1), 5);
        EXPECT_EQ(list.get(2), 7);

        EXPECT_NULL(list.removeAt(-1));
        EXPECT_NULL(list.removeAt(3));

        EXPECT_EQ(list.removeAt(1), 5);
        EXPECT_EQ(list.length, 2);
        EXPECT_EQ(list.head->value, 3);
        EXPECT_EQ(list.tail->value, 7);
        EXPECT_EQ(list.head->next->value, 7);
        EXPECT_EQ(list.tail->prev->value, 3);

        EXPECT_EQ(list.removeAt(1), 7);
        EXPECT_EQ(list.length, 1);
        EXPECT_EQ(list.head->value, 3);
        EXPECT_EQ(list.tail->value, 3);

        EXPECT_EQ(list.removeAt(0), 3);
        EXPECT_NULL_LINKEDLIST(list);

        list.append(3);
        list.append(5);
        list.append(7);

        // 3 5 7

        EXPECT_EQ(list.remove(5), 5);
        EXPECT_EQ(list.length, 2);
        EXPECT_EQ(list.head->value, 3);
        EXPECT_EQ(list.tail->value, 7);
        EXPECT_EQ(list.head->next->value, 7);
        EXPECT_EQ(list.tail->prev->value, 3);

        // 3 7

        list.prepend(0);
        list.prepend(-1);

        //-1 0 3 7

        EXPECT_EQ(list.length, 4);
        EXPECT_EQ(list.head->value, -1);
        EXPECT_EQ(list.tail->value, 7);
        EXPECT_EQ(list.head->next->value, 0);

        list.insertAt(-1, -1);

        EXPECT_EQ(list.length, 4);

        list.insertAt(2, 1);

        //-1 0 1 3 7

        EXPECT_EQ(list.length, 5);
        EXPECT_EQ(list.head->next->next->value, 1);

        list.insertAt(0, -2);
        list.insertAt(5, 9);

        EXPECT_EQ(list.head->value, -2);
        EXPECT_EQ(list.tail->value, 9);
    }

    void EXPECT_NULL_LINKEDLIST(LinkedList<int> list)
    {
        EXPECT_NULLPTR(list.head);
        EXPECT_NULLPTR(list.tail);
        EXPECT_EQ(list.length, 0);
        EXPECT_NULL(list.get(0));
        EXPECT_NULL(list.removeAt(0));
        EXPECT_NULL(list.remove(0));
    }
}
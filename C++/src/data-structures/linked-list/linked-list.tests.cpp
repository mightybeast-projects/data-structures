#include <gtest/gtest.h>
#include "testing-utils.h"
#include "linked-list.h"

using namespace TestingUtils;

TEST(LinkedListTests, LinkedList_IsCorrect)
{
    LinkedList<int> list;

    EXPECT_NULLPTR(list.head);
    EXPECT_NULLPTR(list.tail);
    EXPECT_EQ(list.length, 0);
    EXPECT_NULL(list.get(0));

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
}
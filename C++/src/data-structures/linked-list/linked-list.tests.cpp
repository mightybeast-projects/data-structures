#include <gtest/gtest.h>
#include "testing-utils.h"
#include "linked-list.h"

using namespace TestingUtils;

void EXPECT_NULL_LIST(LinkedList<int> list);

TEST(LinkedListTests, LinkedList_IsCorrect)
{
    LinkedList<int> list;

    EXPECT_NULL_LIST(list);

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
    EXPECT_NULL_LIST(list);

    list.append(3);
    list.append(5);
    list.append(7);

    EXPECT_EQ(list.remove(5), 5);
    EXPECT_EQ(list.length, 2);
    EXPECT_EQ(list.head->value, 3);
    EXPECT_EQ(list.tail->value, 7);
    EXPECT_EQ(list.head->next->value, 7);
    EXPECT_EQ(list.tail->prev->value, 3);
}

void EXPECT_NULL_LIST(LinkedList<int> list)
{
    EXPECT_NULLPTR(list.head);
    EXPECT_NULLPTR(list.tail);
    EXPECT_EQ(list.length, 0);
    EXPECT_NULL(list.get(0));
    EXPECT_NULL(list.removeAt(0));
    EXPECT_NULL(list.remove(0));
}
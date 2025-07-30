#include "linked-list.hpp"
#include "testing-utils.hpp"
#include <gtest/gtest.h>

TEST(Linked_List, Linked_List_Is_Correct)
{
    linkedList::LinkedList<int> list;

    testingUtils::EXPECT_NULLPTR(list.head);
    testingUtils::EXPECT_NULLPTR(list.tail);
    EXPECT_EQ(list.length, 0);

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

    testingUtils::EXPECT_NULL(list.get(-1));
    testingUtils::EXPECT_NULL(list.get(3));
    EXPECT_EQ(list.get(1), 5);
    EXPECT_EQ(list.get(2), 7);

    testingUtils::EXPECT_NULL(list.removeAt(-1));
    testingUtils::EXPECT_NULL(list.removeAt(3));

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

    list.append(3);
    list.append(5);
    list.append(7);

    EXPECT_EQ(list.remove(5), 5);
    EXPECT_EQ(list.length, 2);
    EXPECT_EQ(list.head->value, 3);
    EXPECT_EQ(list.tail->value, 7);
    EXPECT_EQ(list.head->next->value, 7);
    EXPECT_EQ(list.tail->prev->value, 3);

    list.prepend(0);
    list.prepend(-1);

    EXPECT_EQ(list.length, 4);
    EXPECT_EQ(list.head->value, -1);
    EXPECT_EQ(list.tail->value, 7);
    EXPECT_EQ(list.head->next->value, 0);

    list.insertAt(-1, -1);

    EXPECT_EQ(list.length, 4);

    list.insertAt(2, 1);

    EXPECT_EQ(list.length, 5);
    EXPECT_EQ(list.head->next->next->value, 1);

    list.insertAt(0, -2);
    list.insertAt(5, 9);

    EXPECT_EQ(list.head->value, -2);
    EXPECT_EQ(list.tail->value, 9);
}
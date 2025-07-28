#include "linked-list.tests.h"
#include "linked-list.h"
#include "unity.h"

LinkedList* linkedList;

void linkedListSetUp(void)
{
    linkedList = createLinkedList();
}

void linkedListTearDown(void)
{
    deleteLinkedList(linkedList);
}

void Linked_List_Create_Should_Return_Newly_Created_Linked_List()
{
    TEST_ASSERT_NOT_NULL(linkedList);
}

void Newly_Created_Linked_List_Should_Be_Empty()
{
    TEST_ASSERT_TRUE(linkedListIsEmpty(linkedList));
}

void After_One_Append_Linked_List_Should_Not_Be_Empty()
{
    linkedListAppend(linkedList);

    TEST_ASSERT_FALSE(linkedListIsEmpty(linkedList));
}

void After_Two_Appends_And_One_Remove_Linked_List_Should_Not_Be_Empty()
{
    linkedListAppend(linkedList);
    linkedListAppend(linkedList);
    linkedListRemove(linkedList);

    TEST_ASSERT_FALSE(linkedListIsEmpty(linkedList));
}

void Linked_List_Should_Have_Size()
{
    linkedListAppend(linkedList);
    linkedListAppend(linkedList);
    linkedListAppend(linkedList);
    linkedListAppend(linkedList);
    linkedListRemove(linkedList);

    TEST_ASSERT_EQUAL_INT(3, linkedListSize(linkedList));
}

void runLinkedListTests(void)
{
    RUN_TEST(Linked_List_Create_Should_Return_Newly_Created_Linked_List);
    RUN_TEST(Newly_Created_Linked_List_Should_Be_Empty);
    RUN_TEST(After_One_Append_Linked_List_Should_Not_Be_Empty);
    RUN_TEST(After_Two_Appends_And_One_Remove_Linked_List_Should_Not_Be_Empty);
    RUN_TEST(Linked_List_Should_Have_Size);
}
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

void runLinkedListTests(void)
{
    RUN_TEST(Linked_List_Create_Should_Return_Newly_Created_Linked_List);
}
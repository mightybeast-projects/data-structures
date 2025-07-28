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

void Linked_List_Create_Should_Return_Newly_Created_Linked_List(void)
{
    TEST_ASSERT_NOT_NULL(linkedList);
}

void Newly_Created_Linked_List_Should_Be_Empty(void)
{
    TEST_ASSERT_TRUE(linkedListIsEmpty(linkedList));
}

void After_One_Append_Linked_List_Should_Not_Be_Empty(void)
{
    linkedListAppend(linkedList, 1);

    TEST_ASSERT_FALSE(linkedListIsEmpty(linkedList));
}

void After_Two_Appends_And_One_Remove_Linked_List_Should_Not_Be_Empty(void)
{
    linkedListAppend(linkedList, 1);
    linkedListAppend(linkedList, 2);

    linkedListRemove(linkedList, 2);

    TEST_ASSERT_FALSE(linkedListIsEmpty(linkedList));
}

void Linked_List_Should_Have_Size(void)
{
    linkedListAppend(linkedList, 1);
    linkedListAppend(linkedList, 2);
    linkedListAppend(linkedList, 3);
    linkedListAppend(linkedList, 4);

    linkedListRemove(linkedList, 1);

    TEST_ASSERT_EQUAL_INT(3, linkedListSize(linkedList));
}

void Linked_List_Append_Should_Append_New_Value(void)
{
    linkedListAppend(linkedList, 1);
    linkedListAppend(linkedList, 3);

    TEST_ASSERT_EQUAL_INT(3, linkedListGet(linkedList, 1));
}

void Linked_List_Get_Should_Return_Negative_One_If_Passed_Index_Is_Out_Of_Bounds(
    void)
{
    linkedListAppend(linkedList, 1);

    TEST_ASSERT_EQUAL_INT(-1, linkedListGet(linkedList, -1));
    TEST_ASSERT_EQUAL_INT(-1, linkedListGet(linkedList, 1));
}

void After_One_Prepend_Linked_List_Should_Not_Be_Empty(void)
{
    linkedListPrepend(linkedList, 1);

    TEST_ASSERT_FALSE(linkedListIsEmpty(linkedList));
}

void Linked_List_Prepend_Should_Prepend_New_Value(void)
{
    linkedListPrepend(linkedList, 4);
    linkedListPrepend(linkedList, 6);

    TEST_ASSERT_EQUAL_INT(6, linkedListGet(linkedList, 0));
}

void Linked_List_Remove_Should_Return_False_If_List_Does_Not_Contain_Specified_Value(
    void)
{
    linkedListAppend(linkedList, 4);
    linkedListAppend(linkedList, 5);
    linkedListAppend(linkedList, 7);

    TEST_ASSERT_FALSE(linkedListRemove(linkedList, 3));
}

void Linked_List_Remove_On_Empty_List_Should_Return_False(void)
{
    TEST_ASSERT_FALSE(linkedListRemove(linkedList, 4));
}

void Linked_List_Remove_Should_Remove_Value_And_Return_True(void)
{
    linkedListAppend(linkedList, 4);
    linkedListAppend(linkedList, 7);
    linkedListAppend(linkedList, 9);

    const bool result = linkedListRemove(linkedList, 7);

    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_EQUAL_INT(2, linkedListSize(linkedList));
    TEST_ASSERT_EQUAL_INT(9, linkedListGet(linkedList, 1));
}

void Linked_List_Insert_At_Should_Not_Insert_New_Value_If_Index_Is_Out_Of_Bounds(
    void)
{
    linkedListAppend(linkedList, 4);
    linkedListAppend(linkedList, 7);
    linkedListAppend(linkedList, 9);

    linkedListInsertAt(linkedList, -1, 1);
    linkedListInsertAt(linkedList, 4, 1);

    TEST_ASSERT_EQUAL_INT(4, linkedListGet(linkedList, 0));
    TEST_ASSERT_EQUAL_INT(7, linkedListGet(linkedList, 1));
    TEST_ASSERT_EQUAL_INT(9, linkedListGet(linkedList, 2));
    TEST_ASSERT_EQUAL_INT(3, linkedListSize(linkedList));
}

void Linked_List_Insert_At_Zero_Should_Prepend_New_Value(void)
{
    linkedListInsertAt(linkedList, 0, 5);
    linkedListInsertAt(linkedList, 0, 4);

    TEST_ASSERT_EQUAL_INT(4, linkedListGet(linkedList, 0));
    TEST_ASSERT_EQUAL_INT(2, linkedListSize(linkedList));
}

void Linked_List_Insert_At_Should_Insert_New_Value_At_Index(void)
{
    linkedListAppend(linkedList, 4);
    linkedListAppend(linkedList, 7);
    linkedListAppend(linkedList, 9);

    linkedListInsertAt(linkedList, 1, 10);

    TEST_ASSERT_EQUAL_INT(4, linkedListGet(linkedList, 0));
    TEST_ASSERT_EQUAL_INT(10, linkedListGet(linkedList, 1));
    TEST_ASSERT_EQUAL_INT(7, linkedListGet(linkedList, 2));
    TEST_ASSERT_EQUAL_INT(4, linkedListSize(linkedList));
}

void Linked_List_Insert_At_Last_Index_Should_Append_New_Value(void)
{
    linkedListInsertAt(linkedList, 0, 4);
    linkedListInsertAt(linkedList, 1, 3);

    TEST_ASSERT_EQUAL_INT(3, linkedListGet(linkedList, 1));
    TEST_ASSERT_EQUAL_INT(2, linkedListSize(linkedList));
}

void Linked_List_Remove_At_Should_Return_False_If_Index_Is_Out_Of_Bounds()
{
    TEST_ASSERT_FALSE(linkedListRemoveAt(linkedList, -1));
    TEST_ASSERT_FALSE(linkedListRemoveAt(linkedList, 0));
}

void Linked_List_Remove_At_Zero_Should_Remove_Head()
{
    linkedListAppend(linkedList, 3);
    linkedListAppend(linkedList, 6);
    linkedListAppend(linkedList, 7);

    const bool res = linkedListRemoveAt(linkedList, 0);

    TEST_ASSERT_TRUE(res);
    TEST_ASSERT_EQUAL_INT(6, linkedListGet(linkedList, 0));
    TEST_ASSERT_EQUAL_INT(7, linkedListGet(linkedList, 1));
    TEST_ASSERT_EQUAL_INT(2, linkedListSize(linkedList));
}

void Linked_List_Remove_At_Should_Remove_Node_At_Index(void)
{
    linkedListAppend(linkedList, 3);
    linkedListAppend(linkedList, 6);
    linkedListAppend(linkedList, 7);

    const bool res = linkedListRemoveAt(linkedList, 1);

    TEST_ASSERT_TRUE(res);
    TEST_ASSERT_EQUAL_INT(7, linkedListGet(linkedList, 1));
    TEST_ASSERT_EQUAL_INT(2, linkedListSize(linkedList));
}

void Linked_List_Remove_At_Last_Index_Should_Remove_Tail(void)
{
    linkedListAppend(linkedList, 3);
    linkedListAppend(linkedList, 6);
    linkedListAppend(linkedList, 7);

    const bool res = linkedListRemoveAt(linkedList, 2);

    TEST_ASSERT_TRUE(res);
    TEST_ASSERT_EQUAL_INT(6, linkedListGet(linkedList, 1));
    TEST_ASSERT_EQUAL_INT(2, linkedListSize(linkedList));
}

void runLinkedListTests(void)
{
    RUN_TEST(Linked_List_Create_Should_Return_Newly_Created_Linked_List);
    RUN_TEST(Newly_Created_Linked_List_Should_Be_Empty);

    RUN_TEST(After_One_Append_Linked_List_Should_Not_Be_Empty);
    RUN_TEST(After_One_Prepend_Linked_List_Should_Not_Be_Empty);
    RUN_TEST(After_Two_Appends_And_One_Remove_Linked_List_Should_Not_Be_Empty);
    RUN_TEST(Linked_List_Should_Have_Size);

    RUN_TEST(Linked_List_Append_Should_Append_New_Value);

    RUN_TEST(Linked_List_Prepend_Should_Prepend_New_Value);

    RUN_TEST(
        Linked_List_Get_Should_Return_Negative_One_If_Passed_Index_Is_Out_Of_Bounds);

    RUN_TEST(
        Linked_List_Remove_Should_Return_False_If_List_Does_Not_Contain_Specified_Value);
    RUN_TEST(Linked_List_Remove_On_Empty_List_Should_Return_False);
    RUN_TEST(Linked_List_Remove_Should_Remove_Value_And_Return_True);

    RUN_TEST(Linked_List_Insert_At_Should_Insert_New_Value_At_Index);
    RUN_TEST(Linked_List_Insert_At_Zero_Should_Prepend_New_Value);
    RUN_TEST(
        Linked_List_Insert_At_Should_Not_Insert_New_Value_If_Index_Is_Out_Of_Bounds);
    RUN_TEST(Linked_List_Insert_At_Last_Index_Should_Append_New_Value);

    RUN_TEST(
        Linked_List_Remove_At_Should_Return_False_If_Index_Is_Out_Of_Bounds);
    RUN_TEST(Linked_List_Remove_At_Zero_Should_Remove_Head);
    RUN_TEST(Linked_List_Remove_At_Should_Remove_Node_At_Index);
    RUN_TEST(Linked_List_Remove_At_Last_Index_Should_Remove_Tail);
}
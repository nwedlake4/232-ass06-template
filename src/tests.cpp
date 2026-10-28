#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <iostream>

// ============================================================
// PART 2 Tests: DoublyLinkedList
// ============================================================

/// Create a DoublyLinkedList. Verify length() is 0 on a new list.
void test_new_list_is_empty(void)
{
    DoublyLinkedList a;
    TEST_ASSERT_TRUE_MESSAGE(a.length()==0, "List length not 0");
}

/// Create a DoublyLinkedList. Call pushFrontValue and pushBackValue.
/// Verify length() is 2.
void test_push_increases_length(void)
{
    DoublyLinkedList a;

    a.pushFrontValue(5);
    a.pushBackValue(6);
    TEST_ASSERT_TRUE_MESSAGE(a.length()==2, "List length not 2");
}

/// Create an EMPTY DoublyLinkedList.
/// Verify popFrontValue() and popBackValue() both have NO value (has_value() is false).
void test_pop_on_empty_list(void)
{
    DoublyLinkedList a;

    
    TEST_ASSERT_TRUE_MESSAGE(a.popFrontValue().has_value()==false, "has value, should not");
    TEST_ASSERT_TRUE_MESSAGE(a.popBackValue().has_value()==false, "has value, should not");
}

/// Push 1, 2, 3 with pushBackValue.
/// Verify popBackValue() gives 3, then popFrontValue() gives 1, then length() is 1.
void test_pop_order(void)
{
    DoublyLinkedList a;

    a.pushBackValue(1);
    a.pushBackValue(2);
    a.pushBackValue(3);
    std::optional<NodeValue> val1 = a.popBackValue();
    TEST_ASSERT_TRUE_MESSAGE(val1==std::optional<NodeValue>(3), "is not 3");
    std::optional<NodeValue> val2 = a.popFrontValue();
    TEST_ASSERT_TRUE_MESSAGE(val2==std::optional<NodeValue>(1), "is not 1");
    TEST_ASSERT_TRUE_MESSAGE(a.length()==1, "length is not 1");
}

/// Push one value, then call deleteValue with a value that is NOT in the list.
/// Verify it returns false and length() does not change.
void test_delete_value_not_found(void)
{
    DoublyLinkedList a;

    a.pushBackValue(1);
    TEST_ASSERT_TRUE_MESSAGE(a.deleteValue(2)==false, "does not return false");
    TEST_ASSERT_TRUE_MESSAGE(a.length()==1, "length is not 1");
}

/// Push 1, 2, 3 with pushBackValue. Call deleteValue(2).
/// Verify popBackValue() gives 3 and the next popBackValue() gives 1.
/// (popBackValue follows prevPtr: this fails if you forgot to repair the backward link.)
void test_delete_middle_keeps_links(void)
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

// ============================================================
// PART 3 Tests: StdDoublyLinkedList
// ============================================================

/// Push 1, 2, 1 with pushBackValue. Call deleteValue(NodeValue{1}).
/// Verify length() is 2 and popFrontValue() gives 2 (only the FIRST 1 was removed).
void test_std_delete_only_first(void)
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create an EMPTY StdDoublyLinkedList.
/// Verify popFrontValue() and popBackValue() have NO value and do not crash.
void test_std_pop_on_empty_list(void)
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

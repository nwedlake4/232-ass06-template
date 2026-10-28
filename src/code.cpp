// ============================================================
// CSCI 232 Assignment 06 – Doubly Linked List vs. std::list
// Student Implementation
// ============================================================

#include "code.hpp"
#include <algorithm>
#include <iostream>

// Uncomment the author block below and fill in your name:

std::string AUTHOR_NAME       = "Nolan Wedlake";
std::string AUTHOR_AUTHORSHIP = "I acknowledge that I have worked on this "
"assignment independently, except where explicitly noted and referenced. "
"Any collaboration or use of external resources has been properly cited. "
"I am fully aware of the consequences of academic dishonesty and agree "
"to abide by the university's academic integrity policy.";

// ============================================================
// PART 1: Class DoubleNode
// ============================================================

/// Constructor: initialize ALL THREE fields with a member initializer list.
/// value <- newValue, prevPtr <- nullptr, nextPtr <- nullptr.
DoubleNode::DoubleNode(NodeValue newValue) 
    : value(newValue), prevPtr(nullptr), nextPtr(nullptr){}

/// Const getter: return the stored value.
NodeValue DoubleNode::getValue() const
{
    return value;
}

/// Const getter: return the previous node (or nullptr).
DoubleNode *DoubleNode::getPrev() const
{
    return prevPtr;
}

/// Const getter: return the next node (or nullptr).
DoubleNode *DoubleNode::getNext() const
{
    return nextPtr;
}

/// Setter: store newPrevPtr in prevPtr.
void DoubleNode::setPrev(DoubleNode *newPrevPtr)
{
    prevPtr = newPrevPtr;
}

/// Setter: store newNextPtr in nextPtr.
void DoubleNode::setNext(DoubleNode *newNextPtr)
{
    nextPtr = newNextPtr;
}

// ============================================================
// PART 2: Class DoublyLinkedList
// ============================================================

/// Empty list: headPtr = nullptr, tailPtr = nullptr, count = 0.
DoublyLinkedList::DoublyLinkedList() : headPtr(nullptr), tailPtr(nullptr), count(0){}

/// RAII: delete ALL nodes. Save the next pointer BEFORE delete.
DoublyLinkedList::~DoublyLinkedList()
{
    DoubleNode *current = headPtr;

    while (current != NULL) {
        DoubleNode *next = current->getNext();
        delete current;
        current = next;
    }
    headPtr = NULL;
    tailPtr = NULL;
    count = 0;
}

/// Unlink the first node and RETURN it (do not delete it).
/// Fix headPtr, tailPtr, count. Clear the node's own prevPtr and nextPtr.
/// Return nullptr if the list is empty.
DoubleNode *DoublyLinkedList::detachFirst()
{
    if (headPtr == NULL) {
        return nullptr;
    }

    DoubleNode *temp = headPtr;
    headPtr = temp->getNext();
    temp->setNext(nullptr);
    if (headPtr != NULL){
        headPtr->setPrev(nullptr);
    }

    return temp;
}

/// Unlink the last node and RETURN it (do not delete it).
/// Use the tail's prev link. Return nullptr if the list is empty.
DoubleNode *DoublyLinkedList::detachLast()
{
    if (headPtr == NULL){
        return nullptr;
    }

    DoubleNode *temp = tailPtr;
    tailPtr = temp->getPrev();
    temp->setPrev(nullptr);
    if (tailPtr != NULL){
        tailPtr->setNext(nullptr);
    }

    return temp;
}

/// Find the FIRST node equal to value and unlink it (head, tail, only node
/// or middle node). Return nullptr if not found. Reuse detachFirst/detachLast.
DoubleNode *DoublyLinkedList::detachValue(NodeValue value)
{
    DoubleNode *current = headPtr;
    while (current != nullptr) {
        if (current->getValue() == value) {
            if (current == headPtr){
                return detachFirst();
            }
            if (current == tailPtr){
                return detachLast();
            }
            current->getPrev()->setNext(nullptr);
            current->getNext()->setPrev(nullptr);
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            current->setPrev(nullptr);
            current->setNext(nullptr);
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

/// Create a node with new and link it in front. Handle the empty list.
void DoublyLinkedList::pushFrontValue(NodeValue value)
{
    DoubleNode *node = new DoubleNode(value);

    if (headPtr == NULL){
        headPtr = node;
        tailPtr = node;
        count++;
        return;
    }

    node->setNext(headPtr);
    headPtr->setPrev(node);
    headPtr = node;
    count++;
}

/// Create a node with new and link it at the end. Handle the empty list.
void DoublyLinkedList::pushBackValue(NodeValue value)
{
    DoubleNode *node = new DoubleNode(value);

    if(headPtr == NULL){
        headPtr = node;
        tailPtr = node;
        count++;
        return;
    }
    
    node->setPrev(tailPtr);
    tailPtr->setNext(node);
    tailPtr = node;
    count++;
}

/// Detach the first node, read its value, delete the node, return the value.
/// Empty list -> std::nullopt.
std::optional<NodeValue> DoublyLinkedList::popFrontValue()
{
    if (headPtr == NULL)
    return std::nullopt;

    DoubleNode *detachedNode = detachFirst();
    NodeValue value = detachedNode->getValue();
    
    delete detachedNode;
    count--;
    return std::optional<NodeValue>(value);
}

/// Detach the last node, read its value, delete the node, return the value.
/// Empty list -> std::nullopt.
std::optional<NodeValue> DoublyLinkedList::popBackValue()
{
    if (headPtr == NULL)
    return std::nullopt;

    DoubleNode *detachedNode = detachLast();
    NodeValue value = detachedNode->getValue();

    delete detachedNode;
    count--;
    return std::optional<NodeValue>(value);
}

/// Remove the FIRST node equal to value and free it.
/// Return true if something was removed.
bool DoublyLinkedList::deleteValue(NodeValue value)
{
    DoubleNode *temp = detachValue(value);

    if (temp == nullptr){
        return false;
    }

    free(temp);
    return true;
}

/// Return true if any node holds value.
bool DoublyLinkedList::containsValue(NodeValue value) const
{
    // TODO: implement
    return false;
}

/// Print values head -> tail with std::visit (each followed by a space,
/// then a newline). Return the number of printed values.
int DoublyLinkedList::printForward() const
{
    // TODO: implement
    return 0;
}

/// Print values tail -> head using prevPtr. Return the number of printed values.
int DoublyLinkedList::printBackward() const
{
    // TODO: implement
    return 0;
}

/// Return count.
int DoublyLinkedList::length() const
{
    return this->count;
}

// ===== BEGIN PART 3 (do not remove this marker) =====
// ============================================================
// PART 3: Class StdDoublyLinkedList
// ============================================================
// Only std::list methods, <algorithm>, iterators and std::visit.
// A loop is allowed ONLY for printing.

/// Which std::list method inserts at the front?
void StdDoublyLinkedList::pushFrontValue(NodeValue value)
{
    // TODO: implement
}

/// Which std::list method inserts at the back?
void StdDoublyLinkedList::pushBackValue(NodeValue value)
{
    // TODO: implement
}

/// Read the front element, remove it, return it. Empty -> std::nullopt.
std::optional<NodeValue> StdDoublyLinkedList::popFrontValue()
{
    // TODO: implement
    return std::nullopt;
}

/// Read the back element, remove it, return it. Empty -> std::nullopt.
std::optional<NodeValue> StdDoublyLinkedList::popBackValue()
{
    // TODO: implement
    return std::nullopt;
}

/// Remove only the FIRST element equal to value. Return true if removed.
bool StdDoublyLinkedList::deleteValue(NodeValue value)
{
    // TODO: implement
    return false;
}

/// Search without writing your own loop.
bool StdDoublyLinkedList::containsValue(NodeValue value) const
{
    // TODO: implement
    return false;
}

/// Print head -> tail (same format as Part 2). Return the number of values.
int StdDoublyLinkedList::printForward() const
{
    // TODO: implement
    return 0;
}

/// Print tail -> head (same format as Part 2). Return the number of values.
int StdDoublyLinkedList::printBackward() const
{
    // TODO: implement
    return 0;
}

/// size() returns size_t, length() returns int.
int StdDoublyLinkedList::length() const
{
    // TODO: implement
    return 0;
}
// ===== END PART 3 (do not remove this marker) =====

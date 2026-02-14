#include <stdbool.h>

/*
 Problem: Linked List Cycle (LeetCode)

 Description:
 Given the head of a singly linked list, determine whether the list contains a cycle.

 Approach:
 - Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
 - Move one pointer one step at a time (slow pointer).
 - Move another pointer two steps at a time (fast pointer).
 - If both pointers meet, a cycle exists.
 - If fast pointer reaches NULL, the list has no cycle.

 Time Complexity: O(n)
   n = number of nodes in the list

 Space Complexity: O(1)
   Only constant extra space is used.


// Definition for singly-linked list node (as per LeetCode)
struct ListNode {
    int val;
    struct ListNode *next;
};
*/
bool hasCycle(struct ListNode *head) {

    if (head == NULL || head->next == NULL) {
        return false;   // Empty list or single node cannot form a cycle
    }

    struct ListNode *slowPtr = head;
    struct ListNode *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;           // Move slow pointer by 1 step
        fastPtr = fastPtr->next->next;    // Move fast pointer by 2 steps

        if (slowPtr == fastPtr) {
            return true;   // Cycle detected
        }
    }

    return false;   // Reached end, no cycle
}

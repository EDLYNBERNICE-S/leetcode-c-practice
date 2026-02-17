/*
 Definition for singly-linked list.

struct ListNode {
    int val;
    struct ListNode *next;
};


 Problem: Add Two Numbers

 Description:
 Two non-empty linked lists represent two non-negative integers.
 The digits are stored in reverse order.
 Add the two numbers and return the sum as a linked list.

 Example:
 Input: 2 -> 4 -> 3
        5 -> 6 -> 4
 Output: 7 -> 0 -> 8

 Approach:
 - Traverse both lists simultaneously
 - Add corresponding digits + carry
 - Create new nodes for result
 - Continue until both lists AND carry are empty

 Time Complexity: O(max(m, n))
 Space Complexity: O(max(m, n))
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode dummy;   // Dummy head node
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        // Create new node
        struct ListNode* newNode = 
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = sum % 10;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next;
}

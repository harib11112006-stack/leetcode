#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* rotateRight(struct ListNode* head, int k) {
    // Edge case: if list is empty, has 1 node, or no rotation is needed
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    // Step 1: Compute the length of the linked list
    struct ListNode* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    
    // Step 2: Optimize k using modulo arithmetic
    k = k % length;
    if (k == 0) {
        return head; // Rotation brings it back to the exact same position
    }
    
    // Connect tail to head to form a circular loop
    tail->next = head;
    
    // Step 3: Advance to the node just before the new head position
    int stepsToNewTail = length - k - 1;
    struct ListNode* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }
    
    // Step 4: Break the circular loop ring and establish the new head
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    
    return newHead;
}

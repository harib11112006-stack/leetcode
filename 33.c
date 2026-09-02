#include <stdlib.h>

// Definition for singly-linked list is hidden here automatically by LeetCode:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dynamically allocate dummy node to handle head deletion cleanly
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;
    
    // Move fast pointer so that there is a gap of n nodes between fast and slow
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move fast to the end, maintaining the gap
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Bypass the target node
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete); // Prevent memory leak
    
    struct ListNode* newHead = dummy->next;
    free(dummy); // Clean up the auxiliary dummy node
    
    return newHead;
}

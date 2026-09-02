#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;
    
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* groupPrev = &dummy;
    
    while (1) {
        // Check if there are at least k nodes available to reverse
        struct ListNode* kth = groupPrev;
        for (int i = 0; i < k; i++) {
            kth = kth->next;
            if (kth == NULL) {
                return dummy.next; // Fewer than k nodes left; keep them as they are
            }
        }
        
        // Save the start of the next group
        struct ListNode* groupNext = kth->next;
        
        // Reverse the current k-group segment
        struct ListNode* prev = kth->next; 
        struct ListNode* curr = groupPrev->next;
        struct ListNode* nextGroupStart = groupPrev->next; // This becomes the end of the reversed group
        
        while (curr != groupNext) {
            struct ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        // Link the previous group's tail to the new head of this reversed group
        groupPrev->next = kth;
        // Move groupPrev to the tail of the newly reversed group
        groupPrev = nextGroupStart;
    }
    
    return dummy.next;
}

#include <stdlib.h>
#include <stdbool.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    // Create a dummy node on the stack to easily reference the head
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* prev = &dummy;
    
    while (prev->next != NULL) {
        struct ListNode* curr = prev->next;
        bool hasDuplicates = false;
        
        // Scan ahead to find the end of a duplicate sequence
        while (curr->next != NULL && curr->val == curr->next->val) {
            hasDuplicates = true;
            struct ListNode* temp = curr;
            curr = curr->next;
            // Option to free nodes here to prevent memory leaks if required
        }
        
        if (hasDuplicates) {
            // Skip all duplicate nodes by linking directly to the next unique node candidate
            prev->next = curr->next;
        } else {
            // No duplicates found, move prev forward
            prev = prev->next;
        }
    }
    
    return dummy.next;
}

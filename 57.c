#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Phase 1: Determine if a cycle exists and find intersection
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Cycle detected! Move to Phase 2.
            struct ListNode *entry = head;
            
            // Move both pointers at equal speed until they collide
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // This is the start node of the cycle
        }
    }
    
    return NULL; // No cycle found
}

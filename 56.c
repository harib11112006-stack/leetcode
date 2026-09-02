#include <stdbool.h>
#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Advance pointers until fast hits the end of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Moves 1 step
        fast = fast->next->next;    // Moves 2 steps
        
        // If they intersect, a cycle exists
        if (slow == fast) {
            return true;
        }
    }
    
    return false; // Fast reached the end, so no cycle exists
}

#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* swapPairs(struct ListNode* head) {
    // Statically create a dummy node on the stack to simplify head swapping
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* point = &dummy;
    
    // Ensure there are at least two remaining nodes to swap
    while (point->next != NULL && point->next->next != NULL) {
        struct ListNode* swap1 = point->next;
        struct ListNode* swap2 = point->next->next;
        
        // Adjust the pointers to swap the nodes
        swap1->next = swap2->next;
        swap2->next = swap1;
        point->next = swap2;
        
        // Move the pointer forward by two nodes for the next iteration
        point = swap1;
    }
    
    return dummy.next;
}

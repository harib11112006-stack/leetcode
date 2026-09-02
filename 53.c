#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* partition(struct ListNode* head, int x) {
    // Dummy heads on the stack to maintain safe insertion access points
    struct ListNode lessHead;
    struct ListNode greaterHead;
    
    lessHead.next = NULL;
    greaterHead.next = NULL;
    
    struct ListNode* lessTail = &lessHead;
    struct ListNode* greaterTail = &greaterHead;
    
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val < x) {
            lessTail->next = curr;
            lessTail = lessTail->next;
        } else {
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }
    
    // Critical step: Cut off the end of the greater list to avoid infinite cycles
    greaterTail->next = NULL;
    
    // Stitch the two partitioned segments together
    lessTail->next = greaterHead.next;
    
    return lessHead.next;
}

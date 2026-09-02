#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Statically create a dummy node on the stack to clean up heads safely
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    // Append the remaining nodes of whichever list is not empty
    tail->next = (list1 != NULL) ? list1 : list2;
    
    return dummy.next;
}

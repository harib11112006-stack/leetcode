#include <stdlib.h>

// LeetCode automatically defines the struct ListNode behind the scenes:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }

    // Step 1: Find the middle of the linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    struct ListNode* curr = slow->next;
    slow->next = NULL; // Disconnect the first half from the second half
    struct ListNode* prev = NULL;
    struct ListNode* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    // 'prev' now points to the head of the reversed second half

    // Step 3: Merge the two sorted halves alternatively
    struct ListNode* first = head;
    struct ListNode* second = prev;
    while (second != NULL) {
        struct ListNode* tmp1 = first->next;
        struct ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}

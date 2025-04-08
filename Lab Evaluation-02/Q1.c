#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
    struct ListNode *prev;
};

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {  // Correct condition
        return true;
    }

    struct ListNode *front = head, *back = head;

    // Move back to the last node
    while (back->next != head) {
        back = back->next;
    }

    // Compare front and back values
    while (front != back && front->prev != back) {
        if (front->val != back->val) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }

    return true;
}
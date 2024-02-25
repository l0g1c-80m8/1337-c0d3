//
// Created by Rutvik Patel on 2/24/24.
//

#include "include.h"

// solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0, head);
        ListNode *pivot_ptr = head, *prev_pivot_ptr = &dummy;

        while (pivot_ptr) {
            if (pivot_ptr->val >= x) break;
            prev_pivot_ptr = pivot_ptr;
            pivot_ptr = pivot_ptr->next;
        }

        if (!pivot_ptr) return head;

        ListNode *c_ptr = head, *p_ptr = &dummy;

        while (c_ptr and c_ptr->val < x) {
            if (c_ptr->val >= x) {
                p_ptr->next = c_ptr->next;
                c_ptr->next = pivot_ptr->next;
                pivot_ptr->next = c_ptr;
                c_ptr = p_ptr->next;
            }
            else {
                p_ptr = c_ptr;
                c_ptr = c_ptr->next;
            }
        }

        while (c_ptr) {
            if (c_ptr->val < x) {
                prev_pivot_ptr->next = c_ptr;
                p_ptr->next = c_ptr->next;
                c_ptr->next = pivot_ptr;
                c_ptr = p_ptr->next;
                prev_pivot_ptr = prev_pivot_ptr->next; // Move prev_pivot_ptr forward
            }
            else {
                p_ptr = c_ptr;
                c_ptr = c_ptr->next;
            }
        }


        return dummy.next;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    log("All testcases passed!");
}
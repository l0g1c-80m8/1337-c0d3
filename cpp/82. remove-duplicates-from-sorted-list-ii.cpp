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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode dummy(0, head);
        ListNode *b_ptr = &dummy, *f_ptr = head;

        while (f_ptr) {
            bool f_duplicate = false;
            while (f_ptr->next and f_ptr->val == f_ptr->next->val) {
                ListNode* t_ptr = f_ptr;
                f_ptr = f_ptr->next;
                delete t_ptr;
                f_duplicate = true;
            }

            if (f_duplicate) {
                ListNode* t_ptr = f_ptr;
                f_ptr = f_ptr->next;
                delete t_ptr;
            }
            else {
                b_ptr->next = f_ptr;
                b_ptr = b_ptr->next;
                f_ptr = f_ptr->next;
            }
        }

        b_ptr->next = nullptr; // Terminate the list properly
        return dummy.next;
    }
};


// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // submitted directly to leetcode

    log("All testcases passed!");
}
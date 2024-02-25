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

        ListNode* back_ptr = head;
        ListNode* forward_ptr = head;

        while (forward_ptr != nullptr) {
            if (back_ptr->val != forward_ptr->val) {
                back_ptr = back_ptr->next;
                back_ptr->val = forward_ptr->val;
            }
            forward_ptr = forward_ptr->next;
        }

        forward_ptr = back_ptr->next;
        back_ptr->next = nullptr;
        while (forward_ptr != nullptr) {
            ListNode* temp_ptr = forward_ptr;
            forward_ptr = forward_ptr->next;
            delete temp_ptr;
        }

        return head;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // submitted directly to leetcode

    log("All testcases passed!");
}
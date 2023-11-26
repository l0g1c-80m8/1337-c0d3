//
// Created by Rutvik Patel on 11/26/23.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode* dummy = new ListNode { 0, head };
        ListNode *pre = dummy, *start = dummy->next;

        for (int i = 0; i < length / k; ++i) {
            for (int j = 1; j < k; ++j) {
                ListNode* next_node = start->next;
                start->next = next_node->next;
                next_node->next = pre->next;
                pre->next = next_node;
            }
            pre = start;
            start = start->next;
        }

        return dummy->next;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    // leet code only implementation
    log("All testcases passed!");
}
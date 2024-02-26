//
// Created by Rutvik Patel on 2/25/24.
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
private:
    ListNode* seek_to_pos(ListNode* head, int pos) {
        int ctr = 0;
        ListNode* t_ptr = head;

        while (t_ptr and ctr < pos) {
            t_ptr = t_ptr->next;
            ++ctr;
        }

        return t_ptr;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head or left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* l_ptr = seek_to_pos(&dummy, left - 1);
        ListNode* s_ptr = l_ptr->next;

        ListNode* prev = nullptr;
        ListNode* curr = s_ptr;
        ListNode* next = nullptr;

        for (int i = 0; i <= right - left; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        l_ptr->next = prev;
        s_ptr->next = curr;

        return dummy.next;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // solution verified on leetcode

    log("All testcases passed!");
}
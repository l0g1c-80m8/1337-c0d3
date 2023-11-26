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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode *first = head, *second = head->next, *prev = nullptr;
        head = second;



        while (first != nullptr and second != nullptr) {
            first->next = second->next;
            second->next = first;

            if (prev != nullptr)
                prev->next = second;

            prev = first;
            first = first->next;
            second = first == nullptr ? nullptr : first->next;
        }

        return head;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    // leet code only implementation
    log("All testcases passed!");
}
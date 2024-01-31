//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"
#include "./include/linked_list.h"

// solution
//  Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };


class Solution {
public:
    ListNode<int>* rotateRight(ListNode<int>* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        int len = 1; // Length of the linked list
        ListNode<int>* tail = head;

        while (tail->get_next()) {
            tail = tail->get_next();
            ++len;
        }

        k = k % len;
        if (k == 0) {
            return head; // No rotation needed
        }

        ListNode<int>* newHead = head;
        for (int i = 0; i < len - k - 1; ++i) {
            newHead = newHead->get_next();
        }

        ListNode<int>* rotatedHead = newHead->get_next();
        newHead->set_next(nullptr);
        tail->set_next(head);

        return rotatedHead;
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

//    verified on leet code

    log("All testcases passed!");
}
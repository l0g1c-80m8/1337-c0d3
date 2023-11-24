//
// Created by Rutvik Patel on 11/24/23.
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
    ListNode<int>* mergeTwoLists(ListNode<int>* list1, ListNode<int>* list2) {
        ListNode<int> *head = new ListNode<int> {std::numeric_limits<int>::min(), nullptr};
        auto *temp = head, *itr1 = list1, *itr2 = list2;

        while (itr1 != nullptr and itr2 != nullptr) {
            if (itr1->get_value() < itr2->get_value()) {
                temp->set_next(itr1);
                temp = itr1;
                itr1 = itr1->get_next();
            }
            else {
                temp->set_next(itr2);
                temp = itr2;
                itr2 = itr2->get_next();
            }
        }

        while (itr1 != nullptr) {
            temp->set_next(itr1);
            temp = itr1;
            itr1 = itr1->get_next();
        }

        while (itr2 != nullptr) {
            temp->set_next(itr2);
            temp = itr2;
            itr2 = itr2->get_next();
        }

        temp = head->get_next();
        delete head;

        return temp;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    log("All testcases passed!");
}
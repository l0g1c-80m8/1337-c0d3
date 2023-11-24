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
private:
    ListNode<int>* merge_lists(ListNode<int>* list1, ListNode<int>* list2) {
        ListNode<int> *head = new ListNode<int> { std::numeric_limits<int>::min(), nullptr };
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
            temp->set_next(itr1);
            temp = itr2;
            itr2 = itr2->get_next();
        }

        temp = head->get_next();
        delete head;

        return temp;
    }

    ListNode<int>* merge_n_lists(
        std::vector<ListNode<int>*>::iterator list1_start,
        std::vector<ListNode<int>*>::iterator list1_end,
        std::vector<ListNode<int>*>::iterator list2_start,
        std::vector<ListNode<int>*>::iterator list2_end
    ) {
        if (list1_start == list1_end) return nullptr;

        if (std::next(list1_start) == list1_end) return *list1_start;

        auto mid1 = list1_start + std::distance(list1_start, list1_end) / 2;
        auto mid2 = list2_start + std::distance(list2_start, list2_end) / 2;

        return merge_lists(
            merge_n_lists(list1_start, mid1, list2_start, mid2),
            merge_n_lists(mid1, list1_end, mid2, list2_end)
        );
    }

public:
    ListNode<int>* mergeKLists(std::vector<ListNode<int>*>& lists) {
        return merge_n_lists(lists.begin(), lists.end(), lists.end(), lists.end());
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    log("All testcases passed!");
}
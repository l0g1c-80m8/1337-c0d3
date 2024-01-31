//
// Created by Rutvik Patel on 11/20/23.
//

#include "include.h"
#include "./include/linked_list.h"

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
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummy = new ListNode(0, head);
//        ListNode* first = dummy, * second = dummy;
//
//        for (int i = 0; i <= n; i++) second = second->next;
//
//        while (second != nullptr) {
//            first = first->next;
//            second = second->next;
//        }
//
//        second = first->next;
//        first->next = second->next;
//        delete second;
//
//        second = dummy->next;
//        delete dummy;
//
//        return second;
//    }
//};

class Solution {
public:
    LinkedList<int>& removeNthFromEnd(LinkedList<int>& lis, int n) {
        return lis;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    LinkedList<int> arg1 = { 1, 2, 3, 4, 5 }, arg2 = { 1 }, arg3 =  { 1, 2 };
    LinkedList<int> ans1 = { 1, 2, 3, 4, 5 }, ans2 = { 1 }, ans3 =  { 1, 2 };

    std::vector<std::pair<std::pair<LinkedList<int>, int>, LinkedList<int>>> test_cases = {
        { { arg1, 2 }, ans1 },
        { { arg2, 1 }, ans2 },
        { { arg3, 1 }, ans3 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        assert_m(solution.removeNthFromEnd(args.first, args.second) == ans, "Failed!");
    }

//    LinkedList<int> intList = {1, 2, 3, 4, 5};
    LinkedList<int> intList = {1, 2};
    intList.display_list();

    log("All testcases passed!");
}
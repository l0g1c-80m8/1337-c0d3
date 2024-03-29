//
// Created by Rutvik Patel on 3/26/24.
//

#include "include.h"

// solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p or !q) return !p and !q;
        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // solution verified on leetcode

    log("All testcases passed!");
}
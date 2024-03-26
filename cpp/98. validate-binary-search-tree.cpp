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
private:
    bool validate_inorder(TreeNode* node, long long int lower_limit, long long int upper_limit) {
        if (node == nullptr) return true;
        if (node->val < lower_limit || node->val > upper_limit) return false;

        return validate_inorder(node->left, lower_limit, static_cast<long long int>(node->val) - 1) &&
               validate_inorder(node->right, static_cast<long long int>(node->val) + 1, upper_limit);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate_inorder(root, LLONG_MIN, LLONG_MAX);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // solution verified on leetcode

    log("All testcases passed!");
}
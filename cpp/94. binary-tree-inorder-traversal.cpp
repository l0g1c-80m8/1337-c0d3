//
// Created by Rutvik Patel on 2/25/24.
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
    void inorder(TreeNode* node, std::vector<int>& values) {
        if (!node) return;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> values;
        inorder(root, values);
        return values;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // verified on leetcode

    log("All testcases passed!");
}
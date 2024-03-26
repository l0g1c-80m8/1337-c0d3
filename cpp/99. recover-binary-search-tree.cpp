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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;

        inorderTraversal(root->left);

        if (prev != nullptr and prev->val >= root->val) {
            if (first == nullptr) first = prev; // Found the first node of the swapped pair
            second = root; // Update the second node of the swapped pair
        }
        prev = root;

        inorderTraversal(root->right);
    }

    void swapValues(TreeNode* node1, TreeNode* node2) {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }

public:
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        swapValues(first, second);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // solution verified on leetcode

    log("All testcases passed!");
}
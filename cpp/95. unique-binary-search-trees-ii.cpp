//
// Created by Rutvik Patel on 3/7/24.
//

#include "include.h"

// solution

class Solution {
public:
    std::map<std::pair<int, int>, std::vector<TreeNode*>> dp;
    std::vector<TreeNode*> solve(int start , int end) {
        if (start > end) return dp[{ start, end }] = { NULL };

        if (start == end) {
            TreeNode *temp = new TreeNode(start);
            return  dp[{ start, end }] = { temp };
        }

        if (dp.find({ start, end })!= dp.end()) return dp[{start,end}];

        vector<TreeNode*> result;
        for(int i = start; i <= end; ++i){
            auto  a = solve(start, i - 1);
            auto  b = solve(i + 1, end);

            for(auto node : a){
                for(auto c : b){
                    auto  root = new TreeNode(i);
                    root->left = node;
                    root->right=c;
                    result.push_back(root);
                }
            }
        }
        return  dp[{ start, end }] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};


// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // verified on leetcode

    log("All testcases passed!");
}
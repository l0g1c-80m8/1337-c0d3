//
// Created by Rutvik Patel on 11/26/23.
//

#include "include.h"
#include <format>

// solution

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i_idx = 0, f_idx= 1;
        while (f_idx < nums.size()) {
            if (nums[i_idx] != nums[f_idx])
                nums[++i_idx] = nums[f_idx];
            ++f_idx;
        }
        return ++i_idx;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> test_cases = {
        { { 1, 1, 2 }, { 1, 2 } },
        { { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }, { 0, 1, 2, 3, 4 } },
    };


    Solution solution;

    for (auto& [args, ans] : test_cases) {
        int sol = solution.removeDuplicates(args);
        assert_m(sol == ans.size(), "Failed! Sizes don't match.");

        for (int idx = 0; idx < ans.size(); ++idx) {
            std::string error_msg = std::to_string(idx) + " Failed! Error at position " + std::to_string(idx);
            assert_m(ans[idx] == args[idx], error_msg);
        }
    }

    log("All testcases passed!");
}
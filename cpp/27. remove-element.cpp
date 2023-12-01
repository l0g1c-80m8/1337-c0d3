//
// Created by Rutvik Patel on 12/1/23.
//

#include "include.h"
#include <unordered_set>

// solution

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int idx = 0, f_idx = 0;

        while (f_idx < nums.size()) {
            if (nums[f_idx] != val) {
                nums[idx++] = nums[f_idx++];
            }
            else {
                ++f_idx;
            }
        }

        return idx;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::unordered_set<int>>> test_cases = {
        { { { 3, 2, 2, 3 }, 3 }, { 2, 2 } },
        { { { 0, 1, 2, 2, 3, 0, 4, 2 }, 2 }, { 0, 1, 4, 0, 3 } },
    };


    Solution solution;

    for (auto& [args, ans] : test_cases) {
        for (int idx = 0; idx < solution.removeElement(args.first, args.second); ++idx)
            if (not ans.contains(args.first[idx]))
                std::string error_msg = std::to_string(args.first[idx]) + " Failed to find " + std::to_string(args.first[idx]);
    }

    log("All testcases passed!");
}
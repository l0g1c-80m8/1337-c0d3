//
// Created by Rutvik Patel on 1/30/24.
//

#include "include.h"

// solution

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int idx = 0, max_pos = 0;

        while (idx <= max_pos) {
            max_pos = std::max(max_pos, idx + nums[idx]);
            if (max_pos >= nums.size() - 1) return true;
            ++idx;
        }

        return false;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> test_cases = {
        { { 2, 3, 1, 1, 4 }, true },
        { { 3, 2, 1, 0, 4 }, false },
        { { 0 }, true },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.canJump(args) == ans, "Failed!");

    log("All testcases passed!");
}
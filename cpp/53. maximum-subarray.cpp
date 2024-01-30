//
// Created by Rutvik Patel on 1/30/24.
//

#include "include.h"

// solution
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        size_t len = nums.size() - 1;
        std::vector<int> dp(len + 1, std::numeric_limits<int>::min());
        dp[len] = nums[len];

        int max_sum = nums[len];
        for (int idx = static_cast<int>(len) - 1; idx >= 0; --idx) {
            dp[idx] = nums[idx] + std::max(0, dp[idx + 1]);
            max_sum = std::max(max_sum, dp[idx]);
        }

        return max_sum;
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        { { -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6 },
        { { 1 }, 1 },
        { { 5, 4, -1, 7, 8 }, 23 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.maxSubArray(args) == ans, "Failed!");

    log("All testcases passed!");
}
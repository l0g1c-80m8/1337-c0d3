//
// Created by Rutvik Patel on 1/28/24.
//

#include "include.h"

// solution

class Solution {
public:
    int jump(std::vector<int>& dist) {
        std::vector<int> dp(dist.size(), std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int d_idx = 0; d_idx < dp.size(); ++d_idx) {\
            for (int j_idx = d_idx + 1;
                j_idx <= std::min(static_cast<int>(dp.size() - 1), d_idx + dist[d_idx]);
                ++j_idx) {
                dp[j_idx] = std::min(dp[j_idx], 1 + dp[d_idx]);
            }
        }

        return dp.back();
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        { { 2, 3, 1, 1, 4 }, 2 },
        { { 2, 3, 0, 1, 4 }, 2 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.jump(args) == ans, "Failed!");

    log("All testcases passed!");
}
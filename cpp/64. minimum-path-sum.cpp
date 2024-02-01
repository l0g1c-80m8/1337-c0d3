//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int n_rows = static_cast<int>(grid.size()), n_cols = static_cast<int>(grid[0].size());
        std::vector<std::vector<int>> dp (n_rows, std::vector<int> (n_cols, std::numeric_limits<int>::max()));
        dp[0][0] = grid[0][0];

        for (int r_idx = 1; r_idx < n_rows; ++r_idx) dp[r_idx][0] = dp[r_idx - 1][0] + grid[r_idx][0];
        for (int c_idx = 1; c_idx < n_cols; ++c_idx) dp[0][c_idx] = dp[0][c_idx - 1] + grid[0][c_idx];

        for (int r_idx = 1; r_idx < n_rows; ++r_idx)
            for (int c_idx = 1; c_idx < n_cols; ++c_idx)
                dp[r_idx][c_idx] = grid[r_idx][c_idx] + std::min(dp[r_idx - 1][c_idx], dp[r_idx][c_idx - 1]);

        return dp.back().back();
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> test_cases = {
        { { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } }, 7 },
        { { { 1, 2, 3 }, { 4, 5, 6 } }, 12 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.minPathSum(args) == ans, "Failed!");

    log("All testcases passed!");
}
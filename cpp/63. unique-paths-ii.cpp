//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacle_grid) {
        int n_rows = static_cast<int>(obstacle_grid.size()), n_cols = static_cast<int>(obstacle_grid[0].size());
        obstacle_grid[0][0] = 1 - obstacle_grid[0][0];

        for (int idx = 1; idx < n_rows; ++idx)
            obstacle_grid[idx][0] = obstacle_grid[idx - 1][0] * (1 - obstacle_grid[idx][0]);

        for (int idx = 1; idx < n_cols; ++idx)
            obstacle_grid[0][idx] = obstacle_grid[0][idx - 1] * (1 - obstacle_grid[0][idx]);

        for (int i = 1; i < n_rows; ++i)
            for (int j = 1; j < n_cols; ++j)
                obstacle_grid[i][j] = (obstacle_grid[i - 1][j] + obstacle_grid[i][j - 1]) * (1 - obstacle_grid[i][j]);

        return obstacle_grid.back().back();
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> test_cases = {
        { { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0} }, 2 },
        { { { 0, 1 }, { 0, 0 } }, 1 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.uniquePathsWithObstacles(args) == ans, "Failed!");

    log("All testcases passed!");
}
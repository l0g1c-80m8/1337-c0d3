//
// Created by Rutvik Patel on 1/28/24.
//

#include "include.h"

// solution
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        for (int r_idx = 0; r_idx < matrix.size(); ++r_idx)
            for (int c_idx = r_idx; c_idx < matrix[r_idx].size(); ++c_idx)
                std::swap(matrix[r_idx][c_idx], matrix[c_idx][r_idx]);

        for (auto& row : matrix)
            for (int idx = 0; idx < row.size() / 2; ++idx)
                std::swap(row[idx], row[matrix[idx].size() - idx - 1]);
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> test_cases = {
        {
            { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
            { { 7, 4, 1 }, { 8, 5, 2 }, { 9, 6, 3 } }
        },
        {
            { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } },
            { { 15, 13, 2, 5 }, { 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 } }
        },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        solution.rotate(args);
        assert_m(args == ans, "Failed");
    }

    log("All testcases passed!");
}
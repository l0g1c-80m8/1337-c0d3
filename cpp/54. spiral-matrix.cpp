//
// Created by Rutvik Patel on 1/30/24.
//

#include "include.h"

// solution

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> spiral_order_traversal;

        int row_lim_start = 0, row_lim_end = static_cast<int>(matrix.size()) - 1;
        int col_lim_start = 0, col_lim_end = static_cast<int>(matrix[0].size()) - 1;
        int case_order = 0;

        while (row_lim_start <= row_lim_end and col_lim_start <= col_lim_end) {
            switch (case_order) {
                case 0: {
                    for (int c_idx = col_lim_start; c_idx <= col_lim_end; ++c_idx)
                        spiral_order_traversal.push_back(matrix[row_lim_start][c_idx]);
                    ++row_lim_start;
                    break;
                }
                case 1: {
                    for (int r_idx = row_lim_start; r_idx <= row_lim_end; ++r_idx)
                        spiral_order_traversal.push_back(matrix[r_idx][col_lim_end]);
                    --col_lim_end;
                    break;
                }
                case 2: {
                    for (int c_idx = col_lim_end; c_idx >= col_lim_start; --c_idx)
                        spiral_order_traversal.push_back(matrix[row_lim_end][c_idx]);
                    --row_lim_end;
                    break;
                }
                case 3: {
                    for (int r_idx = row_lim_end; r_idx >= row_lim_start; --r_idx)
                        spiral_order_traversal.push_back(matrix[r_idx][col_lim_start]);
                    ++col_lim_start;
                    break;
                }
            }

            case_order = (case_order + 1) % 4;
        }

        return spiral_order_traversal;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<int>>> test_cases = {
        { { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }, { 1, 2, 3, 6, 9, 8, 7, 4, 5 } },
        { { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } }, { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.spiralOrder(args) == ans, "Failed!");

    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 2/8/24.
//

#include "include.h"

// solution
class Solution {
private:
    void set_row_value(std::vector<std::vector<int>>& matrix, int r_idx, int value = 0) {
        for (int c_idx = 0; c_idx < matrix[r_idx].size(); ++c_idx)
            matrix[r_idx][c_idx] = value;
    }
    void set_col_value(std::vector<std::vector<int>>& matrix, int c_idx, int value = 0) {
        for (int r_idx = 0; r_idx < matrix.size(); ++r_idx)
            matrix[r_idx][c_idx] = value;
    }
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<int> zero_r_idx, zero_c_idx;

        for (int r_idx = 0 ; r_idx < matrix.size(); ++r_idx) {
            for (int c_idx = 0; c_idx < matrix[r_idx].size(); ++c_idx) {
                if (matrix[r_idx][c_idx] == 0) {
                    zero_r_idx.push_back(r_idx);
                    zero_c_idx.push_back(c_idx);
                }
            }
        }

        for (auto r_idx : zero_r_idx) set_row_value(matrix, r_idx, 0);
        for (auto c_idx : zero_c_idx) set_col_value(matrix, c_idx, 0);

    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> test_cases = {
        { { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } }, { { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 } } },
        {
            { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } },
            { { 0, 0, 0, 0 }, { 0, 4, 5, 0 }, { 0, 3, 1, 0 } }
        },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        solution.setZeroes(args);
        assert_m(args == ans, "Failed!");
    }

    log("All testcases passed!");
}
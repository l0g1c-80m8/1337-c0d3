//
// Created by Rutvik Patel on 2/8/24.
//

#include "include.h"

// solution
class Solution {
private:
    bool binary_search(std::vector<std::vector<int>>& matrix, int target, int n_rows, int n_cols, int s, int e) {
        if (s > e) return false;

        int m = (s + e) / 2;
        int r_idx = m / n_cols, c_idx = m % n_cols;

        if (matrix[r_idx][c_idx] == target) return true;
        if (matrix[r_idx][c_idx] < target) return binary_search(matrix, target, n_rows, n_cols, m + 1, e);
        return binary_search(matrix, target, n_rows, n_cols, s, m - 1);
    }
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int n_rows = static_cast<int>(matrix.size());
        int n_cols = static_cast<int>(matrix[0].size());
        return binary_search(matrix, target, n_rows, n_cols, 0, n_rows * n_cols - 1);
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<std::vector<int>>, int>, bool>> test_cases = {
        { { { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } }, 3 }, true },
        { { { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } }, 13 }, false },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.searchMatrix(args.first, args.second) == ans, "Failed!");


    log("All testcases passed!");
}
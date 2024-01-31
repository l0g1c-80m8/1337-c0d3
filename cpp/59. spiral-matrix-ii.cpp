//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int> (n, 0));

        int r_lim_s = 0, r_lim_e = n - 1, c_lim_s = 0, c_lim_e = n - 1;
        int case_num = 0;
        int counter = 1;

        while (r_lim_e >= r_lim_s and c_lim_e >= c_lim_s) {
            switch (case_num) {
                case 0: {
                    for (int c_idx = c_lim_s; c_idx <= c_lim_e; ++c_idx)
                        matrix[r_lim_s][c_idx] = counter++;
                    ++r_lim_s;
                    break;
                }
                case 1: {
                    for (int r_idx = r_lim_s; r_idx <= r_lim_e; ++r_idx)
                        matrix[r_idx][c_lim_e] = counter++;
                    --c_lim_e;
                    break;
                }
                case 2: {
                    for (int c_idx = c_lim_e; c_idx >= c_lim_s; --c_idx)
                        matrix[r_lim_e][c_idx] = counter++;
                    --r_lim_e;
                    break;
                }
                case 3: {
                    for (int r_idx = r_lim_e; r_idx >= r_lim_s; --r_idx)
                        matrix[r_idx][c_lim_s] = counter++;
                    ++c_lim_s;
                    break;
                }
            }
            case_num = ++case_num % 4;
        }

        return matrix;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, std::vector<std::vector<int>>>> test_cases = {
        { 3, { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } },
        { 1, { { 1 } } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.generateMatrix(args) == ans, "Failed!");

    log("All testcases passed!");
}
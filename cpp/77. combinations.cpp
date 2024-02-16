//
// Created by Rutvik Patel on 2/15/24.
//

#include "include.h"

// solution
class Solution {
private:
    void fill_combinations(
        std::vector<std::vector<int>>& combinations,
        std::vector<int>& combination,
        int s_num,
        int e_num,
        int d_count
        ) {
        if (d_count == 0) {
            combinations.emplace_back(combination);
            return;
        }

        for (int idx = s_num; idx <= e_num; ++idx) {
            combination.push_back(idx);
            fill_combinations(combinations, combination, idx + 1, e_num, d_count - 1);
            combination.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> combination;
        fill_combinations(combinations, combination, 1, n, k);
        return combinations;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, std::vector<std::vector<int>>>> test_cases = {
        { { 4, 2 }, { { 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 3, 4 } } },
        { { 1, 1 }, { { 1 } } },
        { { 4, 3 }, { { 1, 2, 3 }, { 1, 2, 4 }, { 1, 3, 4 }, { 2, 3, 4 } } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.combine(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
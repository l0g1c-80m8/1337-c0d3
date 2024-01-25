//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"
#include <set>

// solution

class Solution {
private:
    static void fill_combinations(
        std::vector<int>& candidates,
        int target,
        std::set<std::vector<int>>& combinations,
        std::vector<int>& potential_combination
        ) {
        if (target < 0) return;
        if (target == 0) {
            std::vector<int> valid_combination(potential_combination);
            std::sort(valid_combination.begin(), valid_combination.end());
            combinations.insert(valid_combination);
            return;
        }

        for (auto candidate : candidates) {
            potential_combination.push_back(candidate);
            fill_combinations(candidates, target - candidate, combinations, potential_combination);
            potential_combination.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::set<std::vector<int>> combinations;
        std::vector<int> potential_combination;
        fill_combinations(candidates, target, combinations, potential_combination);

        return {combinations.begin(), combinations.end()};
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<std::vector<int>>>> test_cases = {
        { { { 2, 3, 6, 7 }, 7 }, { { 2, 2, 3 }, { 7 } } },
        { { { 2, 3, 5 }, 8 }, { { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } } },
        { { { 2 }, 1 }, {  } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.combinationSum(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"
#include <set>

// solution

class Solution {
private:
    void fill_combinations(
        std::vector<int>& nums,
        int s_idx,
        int target,
        std::vector<int>& potential_combination,
        std::vector<std::vector<int>>& combinations
        )
    {
        if (target == 0) {
            combinations.push_back(potential_combination);
            return;
        }
        for (int idx = s_idx; idx < nums.size(); ++idx) {
            if (idx > s_idx and nums[idx] == nums[idx - 1]) continue;
            if (nums[idx] > target) break;

            potential_combination.push_back(nums[idx]);
            fill_combinations(nums, idx + 1, target - nums[idx], potential_combination, combinations);
            potential_combination.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<int> potential_combination;
        std::vector<std::vector<int>> combinations;
        fill_combinations(candidates, 0, target, potential_combination, combinations);
        return combinations;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<std::vector<int>>>> test_cases = {
        { { { 10, 1, 2, 7, 6, 1, 5 }, 8 }, { { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } } },
        { { { 2, 5, 2, 1, 2 }, 5 }, { { 1, 2, 2 }, { 5 } } },
        { { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 27 }, {  } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.combinationSum2(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
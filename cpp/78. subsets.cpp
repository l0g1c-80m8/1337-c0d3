//
// Created by Rutvik Patel on 2/15/24.
//

#include "include.h"

// solution
class Solution {
private:
    void generate_subsets(
        std::vector<int>& nums,
        int s_idx,
        std::vector<int>& subset,
        std::vector<std::vector<int>>& subsets
    ) {
        subsets.emplace_back(subset);
        for (int idx = s_idx; idx < nums.size(); ++idx) {
            subset.push_back(nums[idx]);
            generate_subsets(nums, idx + 1, subset, subsets);
            subset.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> subsets;
        std::vector<int> subset;
        generate_subsets(nums, 0, subset, subsets);
        return subsets;
    }

};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<std::vector<int>>>> test_cases = {
        { { 1, 2, 3 }, { {}, { 1 }, { 1, 2 }, { 1, 2, 3 }, { 1, 3 }, { 2 }, { 2, 3 }, { 3 } } },
        { { 0 }, { {}, { 0 } } },
        { {}, { {} } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.subsets(args) == ans, "Failed!");

    log("All testcases passed!");
}
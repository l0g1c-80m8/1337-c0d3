//
// Created by Rutvik Patel on 1/28/24.
//

#include "include.h"
#include <set>

// solution
class Solution {
private:
    void generate_permutation(
        std::vector<int>& nums,
        std::vector<int>& bit_mask,
        std::vector<int>& permutation,
        std::set<std::vector<int>>& permutations
    ) {
        if (std::all_of(bit_mask.begin(), bit_mask.end(), [](auto it) { return it == 1; })) {
            permutations.insert(std::vector<int>(permutation));
            return;
        }

        for (int idx = 0; idx < nums.size(); ++idx) {
            if (bit_mask[idx] == 1) continue;
            bit_mask[idx] = 1;
            permutation.push_back(nums[idx]);
            generate_permutation(nums, bit_mask, permutation, permutations);
            bit_mask[idx] = 0;
            permutation.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<int> bit_mask(nums.size(), 0), permutation;
        std::set<std::vector<int>> permutations;
        generate_permutation(nums, bit_mask, permutation, permutations);
        return { permutations.begin(), permutations.end() };
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<std::vector<int>>>> testcases = {
        { { 1, 1, 2 }, { { 1, 1, 2 }, { 1, 2, 1 }, { 2, 1, 1 } } },
        { { 1, 2, 3 }, { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } } },
    };

    Solution solution;

    for (auto& [args, ans] : testcases)
        assert_m(solution.permuteUnique(args) == ans, "Failed!");

    log("All testcases passed!");
}
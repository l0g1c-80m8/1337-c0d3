//
// Created by Rutvik Patel on 12/17/23.
//

#include "include.h"

// solution

class Solution {
public:
    std::vector<int> nextPermutation(std::vector<int>& nums) {
//        std::next_permutation(nums.begin(), nums.end());
//        return nums;

        size_t p_idx = nums.size() - 1;
        while (p_idx > 0 && nums[p_idx - 1] >= nums[p_idx]) --p_idx;
        if (p_idx == 0) {
            std::reverse(nums.begin(), nums.end());
            return nums;
        }

        size_t m_idx = nums.size() - 1;
        while (nums[m_idx] <= nums[p_idx - 1]) --m_idx;
        std::swap(nums[p_idx - 1], nums[m_idx]);
        std::reverse(nums.begin() + p_idx, nums.end());

        return nums;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> test_cases = {
        { { 1, 2, 3, }, { 1, 3, 2 } },
        { { 3, 2, 1 }, { 1, 2, 3 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.nextPermutation(args) == ans, "Failed!");

    log("All testcases passed!");
}
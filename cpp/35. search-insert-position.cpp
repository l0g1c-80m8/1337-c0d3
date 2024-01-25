//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"

// solution

class Solution {
private:
    int binarySearch(std::vector<int>& nums, int target, int s_idx, int e_idx) {
        if (s_idx > e_idx) return s_idx;

        int m_idx = (s_idx + e_idx) / 2;

        if (target == nums[m_idx]) return m_idx;
        if (target < nums[m_idx]) return binarySearch(nums, target, s_idx, m_idx - 1);
        return binarySearch(nums, target, m_idx + 1, e_idx);
    }
public:
    int searchInsert(std::vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> test_cases = {
        { { { 1, 3, 5, 6 }, 5 }, 2 },
        { { { 1, 3, 5, 6 }, 2 }, 1 },
        { { { 1, 3, 5, 6 }, 7 }, 4 },
        { { { 1, 3, 5, 6 }, 0 }, 0 },
    };

    Solution solution;

    for(auto& [args, ans] : test_cases)
        assert_m(solution.searchInsert(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
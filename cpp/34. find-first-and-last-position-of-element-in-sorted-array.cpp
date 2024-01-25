//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"

// solution

class Solution {
private:
    std::vector<int> expandRange(std::vector<int>& nums, int target, int h_idx) {
        int s_idx, e_idx;

        for (s_idx = h_idx; s_idx >= 0; --s_idx)
            if (nums[s_idx] != target) break;

        for (e_idx = h_idx; e_idx < nums.size(); ++e_idx)
            if (nums[e_idx] != target) break;

        return { ++s_idx, --e_idx };
    }
    int binarySearch(std::vector<int>& nums, int target, int s_idx, int e_idx) {
        if (s_idx > e_idx) return -1;

        int m_idx = (s_idx + e_idx) / 2;

        if (target == nums[m_idx]) return m_idx;
        if (target < nums[m_idx]) return binarySearch(nums, target, s_idx, m_idx - 1);
        return binarySearch(nums, target, m_idx + 1, e_idx);
    }
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int h_idx = binarySearch(nums, target, 0, nums.size() - 1);
        if (h_idx == -1) return { -1, -1 };
        log ("h_idx: ", h_idx);
        return expandRange(nums, target, h_idx);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>> test_cases = {
        { { { 5, 7, 7, 8, 8, 10 }, 8 }, { 3, 4 } },
        { { { 5, 7, 7, 8, 8, 10 }, 6 }, { -1, -1 } },
        { { {  }, 0 }, { -1, -1 } },
        { { { 1 }, 1 }, { 0, 0 } },
    };

    Solution solution;

    for (auto& [args, ans]: test_cases)
        assert_m(solution.searchRange(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
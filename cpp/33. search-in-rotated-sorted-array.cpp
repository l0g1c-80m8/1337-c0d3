//
// Created by Rutvik Patel on 1/24/24.
//

#include "include.h"

// solution

class Solution {
private:
    int modified_binary_search(std::vector<int>& nums, int target, int s_idx, int e_idx) {
        if (s_idx > e_idx)
            return -1;

        int m_idx = (s_idx + e_idx) / 2;
        if (nums[m_idx] == target)
            return m_idx;

        if (nums[s_idx] <= nums[m_idx]) {
            if (target >= nums[s_idx] and target < nums[m_idx])
                return modified_binary_search(nums, target, s_idx, m_idx - 1);
            else
                return modified_binary_search(nums, target, m_idx + 1, e_idx);
        }
        else {
            if (target > nums[m_idx] and target <= nums[e_idx])
                return modified_binary_search(nums, target, m_idx + 1, e_idx);
            else
                return modified_binary_search(nums, target, s_idx, m_idx - 1);
        }
    }
public:
    int search(std::vector<int>& nums, int target) {
        return modified_binary_search(nums, target, 0, nums.size() - 1);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> test_cases = {
        { { { 4, 5, 6, 7, 0, 1, 2 }, 0 }, 4 },
        { { { 4, 5, 6, 7, 0, 1, 2 }, 3 }, -1 },
        { { { 1 }, 0 }, -1 },
        { { { 5, 1, 3 }, 3 }, 2 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.search(args.first, args.second) == ans, "Failed! ");

    log("All testcases passed!");
}
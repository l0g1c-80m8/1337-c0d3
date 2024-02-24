//
// Created by Rutvik Patel on 2/24/24.
//

#include "include.h"

// solution
class Solution {
private:
    bool modified_binary_search(std::vector<int>& nums, int target, int s_idx, int e_idx) {
        if (s_idx > e_idx) return false;

        int m_idx = (s_idx + e_idx) / 2;
        if (nums[m_idx] == target) return true;

        if (nums[s_idx] < nums[m_idx]) {
            if (target >= nums[s_idx] and target < nums[m_idx])
                return modified_binary_search(nums, target, s_idx, m_idx - 1);
            else
                return modified_binary_search(nums, target, m_idx + 1, e_idx);
        }
        else if (nums[m_idx] < nums[e_idx]) {
            if (target > nums[m_idx] and target <= nums[e_idx])
                return modified_binary_search(nums, target, m_idx + 1, e_idx);
            else
                return modified_binary_search(nums, target, s_idx, m_idx - 1);
        }
        else {
            if (nums[s_idx] == nums[m_idx]) ++s_idx;
            if (nums[e_idx] == nums[m_idx]) --e_idx;
            return modified_binary_search(nums, target, s_idx, e_idx);
        }
    }
public:
    bool search(std::vector<int>& nums, int target) {
        return modified_binary_search(nums, target, 0, static_cast<int>(nums.size() - 1));
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, bool>> test_cases = {
        { { { 2, 5, 6, 0, 0, 1, 2 }, 0 }, true },
        { { { 2, 5, 6, 0, 0, 1, 2 }, 3 }, false },
        { { { 1 }, 0 }, false },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.search(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
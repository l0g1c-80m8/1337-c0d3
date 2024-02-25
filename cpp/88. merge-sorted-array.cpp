//
// Created by Rutvik Patel on 2/24/24.
//

#include "include.h"

// solution
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int idx_1 = 0, idx_2 = 0, idx_m = 0;
        std::vector<int> nums_merged(m + n, -1);

        while (idx_1 < m and idx_2 < n) {
            if (nums1[idx_1] < nums2[idx_2]) nums_merged[idx_m++] = nums1[idx_1++];
            else nums_merged[idx_m++] = nums2[idx_2++];
        }
        while (idx_1 < m) nums_merged[idx_m++] = nums1[idx_1++];
        while (idx_2 < n) nums_merged[idx_m++] = nums2[idx_2++];

        std::copy(nums_merged.begin(), nums_merged.end(), nums1.begin());
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, std::vector<int>, int>, std::vector<int>>> test_cases = {
        { { { 1, 2, 3, 0, 0, 0 }, 3, { 2, 5, 6 }, 3 }, { 1, 2, 2, 3, 5, 6 } },
        { { { 1 }, 1, { }, 0 }, { 1 } },
        { { { 0 }, 0, { 1 }, 1 }, { 1 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        auto& [nums1, m, nums2, n] = args;
        solution.merge(nums1, m, nums2, n);
        assert(nums1 == ans);
    }

    log("All testcases passed!");
}
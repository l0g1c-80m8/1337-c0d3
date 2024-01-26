//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"

// solution

class Solution {
public:
    int trap(std::vector<int>& height) {
        std::vector<int> max_height_before = { 0 }, max_height_after = { 0 };

        int max_height = 0;
        for (int idx = 1; idx < height.size(); ++idx) {
            max_height = std::max(max_height, height[idx - 1]);
            max_height_before.push_back(max_height);
        }

        max_height = 0;
        for (int idx = static_cast<int>(height.size()) - 2; idx >= 0; --idx) {
            max_height = std::max(max_height, height[idx + 1]);
            max_height_after.push_back(max_height);
        }
        std::reverse(max_height_after.begin(), max_height_after.end());

        int capacity = 0;
        for (int idx = 0; idx < height.size(); ++idx)
            capacity += std::max(std::min(max_height_before[idx], max_height_after[idx]) - height[idx], 0);

        return capacity;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        { { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }, 6 },
        { { 4, 2, 0, 3, 2, 5 }, 9 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.trap(args) == ans, "Failed!");

    log("All testcases passed!");
}
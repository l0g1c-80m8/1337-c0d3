//
// Created by Rutvik Patel on 11/18/23.
//

#include "include.h"

// solution

class Solution {
private:
    int get_area(std::vector<int>& height, int start_idx, int end_idx) {
        return (end_idx - start_idx) * std::min(height[start_idx], height[end_idx]);
    }
public:
    int maxArea(std::vector<int>& height) {
        int start_idx = 0, end_idx = height.size() - 1;
        int max_area = get_area(height, start_idx, end_idx);

        while (start_idx < end_idx) {
            max_area = std::max(get_area(height, start_idx, end_idx), max_area);

            if (height[start_idx] < height[end_idx])
                start_idx++;
            else
                end_idx--;
        }

        return max_area;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        { { 1, 1 }, 1 },
        { { 1, 8, 6, 2, 5, 4, 8, 3, 7 }, 49 },
    };

    Solution solution;

    for (auto [heights, capacity] : test_cases)
        assert_m(solution.maxArea(heights) == capacity, "Failed!");

    log("All test cases passed!");
}
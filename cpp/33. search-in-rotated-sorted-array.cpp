//
// Created by Rutvik Patel on 1/24/24.
//

#include "include.h"

// solution

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        return -1;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> test_cases = {
        { { { 4, 5, 6, 7, 0, 1, 2 }, 0 }, 4 },
        { { { 4, 5, 6, 7, 0, 1, 2 }, 3 }, -1 },
        { { { 1 }, 0 }, -1 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.search(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
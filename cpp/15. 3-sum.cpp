//
// Created by Rutvik Patel on 11/19/23.
//

#include "include.h"
#include <algorithm>
#include <set>
#include <unordered_map>

// solution

class Solution {
public:
    std::set<std::array<int, 3>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::array<int, 3>> triples;

        for (auto f_itr = nums.begin(); f_itr < nums.end(); f_itr++) {
            auto start_itr = f_itr + 1, end_itr = nums.end() - 1;

            while (start_itr < end_itr) {
                if (*start_itr + *end_itr + *f_itr > 0)
                    end_itr--;
                else if (*start_itr + *end_itr + *f_itr < 0)
                    start_itr++;
                else {
                    triples.insert({ *f_itr, *start_itr, *end_itr });
                    start_itr++;
                }
            }
        }

        return triples;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::set<std::array<int, 3>>>> test_cases = {
        { { -1, 0, 1, 2, -1, -4 }, { { -1, -1, 2 }, { -1, 0, 1 } } },
        { { 0, 1, 1 }, {} },
        { { 0, 0, 0 }, { { 0, 0, 0 } } },
        { { -1, 0, 1, 0 }, { { -1, 0, 1 } } },
        { { -2, 0, 1, 1, 2 }, { { -2, 0, 2 }, { -2, 1, 1 } } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.threeSum(args) == ans, "Failed!");

    log("All testcases passed!");
}
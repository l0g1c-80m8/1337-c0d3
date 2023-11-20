//
// Created by Rutvik Patel on 11/20/23.
//

#include "include.h"
#include <set>

// solution

class Solution {
public:
    std::set<std::array<int, 4>> fourSum(std::vector<int>& nums, int target) {
//        std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
//            std::set<std::vector<int>> quadruples;
        std::set<std::array<int, 4>> quadruples;
        std::sort(nums.begin(), nums.end());

        for (auto f_itr = nums.begin(); f_itr < nums.end() - 3; f_itr++) {
            for (auto s_itr = f_itr + 1; s_itr < nums.end() - 2; s_itr++) {
                auto start_itr = s_itr + 1, end_itr = nums.end() - 1;
                while (start_itr < end_itr ) {
                    auto diff = (long) *start_itr + *end_itr + *f_itr + *s_itr - target;
                    if (diff > 0)
                        end_itr--;
                    else if (diff < 0)
                        start_itr++;
                    else {
                        quadruples.insert({ *f_itr, *s_itr, *start_itr, *end_itr });
                        start_itr++;
                    }
                }
            }
        }

        return quadruples;
//        return std::vector<std::vector<int>> (quadruples.begin(), quadruples.end());

    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, std::set<std::array<int, 4>>>> test_cases = {
        { { { 1, 0, -1, 0, -2, 2 }, 0 }, { { -2, -1, 1, 2 }, { -2, 0, 0, 2 }, { -1, 0, 0, 1 } } },
        { { { 2, 2, 2, 2, 2 }, 8 }, { { 2, 2, 2, 2 } } },
        { { { -3, -1, 0, 2, 4, 5 }, 0 }, { { -3, -1, 0, 4 } } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.fourSum(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
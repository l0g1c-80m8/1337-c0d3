//
// Created by Rutvik Patel on 11/20/23.
//

#include "include.h"

// solution
class Solution {

public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        long closest_sum = std::numeric_limits<int>::max();
        bool found_exact = false;

        for (auto f_itr = nums.begin(); f_itr < nums.end() - 2 and not found_exact; f_itr++) {
            auto start_itr = f_itr + 1, end_itr = nums.end() - 1;

            while (start_itr < end_itr) {
                long curr_sum = *f_itr + *start_itr + *end_itr;
                if (curr_sum > target)
                    end_itr--;
                else if (curr_sum < target)
                    start_itr++;
                else {
                    closest_sum = target;
                    found_exact = true;
                    break;
                }
                closest_sum = std::abs(closest_sum - target) < std::abs(curr_sum - target) ? closest_sum : curr_sum;
            }
        }

        return static_cast<int>(closest_sum);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> test_cases = {
        { { { -1, 2, 1, -4 }, 1 }, 2 },
        { { { 0, 0, 0 }, 1 }, 0 },
        { { { 0, 1, 2 }, 3 }, 3 },
        { { { 1, 1, 1, 1 }, -100 }, 3 },
        { { { 4, 0, 5, -5, 3, 3, 0, -4, -5 }, -2 }, -2 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.threeSumClosest(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 2/23/24.
//

#include "include.h"

// solution
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int s_ptr = 0, f_ptr = -1;

        while (++f_ptr < nums.size())
            if (s_ptr < 2 or nums[f_ptr] > nums[s_ptr - 2])
                nums[s_ptr++] = nums[f_ptr];

        return s_ptr;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> test_cases = {
        { { 1, 1, 1, 2, 2, 3 }, { 1, 1, 2, 2, 3 } },
        { { 0, 0, 1, 1, 1, 1, 2, 3, 3 }, { 0, 0, 1, 1, 2, 3, 3 } },
        { { 1 }, { 1 } },
        { { 1, 1, 1, 1 }, { 1, 1 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        int l_idx = solution.removeDuplicates(args);
        assert_m(std::vector<int> (args.begin(), args.begin() + l_idx) == ans, "Failed!");
    }

    log("All testcases passed!");
}
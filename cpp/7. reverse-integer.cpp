//
// Created by Rutvik Patel on 11/17/23.
//

#include "include.h"

#include <iostream>

class Solution {
public:
    Solution() = default;

    static int reverse(int x) {
        if (x == 0)
            return 0;

        int sign = x / std::abs(x);
        int rev = 0;
        int digit = 0;

        x = std::abs(x);
        while (x > 0) {
            digit = x % 10;
            x /= 10;

            if (rev > std::numeric_limits<int32_t>::max() / 10) {
                rev = 0;
                break;
            }

            rev = rev * 10 + digit;
        }
        rev *= sign;

        return rev;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int32_t, int32_t>> test_cases = {
        {32, 23},
        {123, 321},
        {-123, -321},
        {120, 21},
        {2'147'483'647, 0},
        {1'234'567, 7'654'321},
        {-2'147'483'648, 0},
        {-32, -23},
        {0, 0},
        {8, 8},
        {2, 2},
        {-2, -2},
        {11, 11},
        {-11, -11},
    };

    Solution solution;
    for (auto [orig, rev] : test_cases)
        assert_m(solution.reverse(orig) == rev, "Failed!");

    log("All test cases passed!");
}
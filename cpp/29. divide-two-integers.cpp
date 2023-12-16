//
// Created by Rutvik Patel on 12/16/23.
//

#include "include.h"

// solution

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == std::numeric_limits<int>::min() and divisor == -1)
            return std::numeric_limits<int>::max();

        long long dvd = labs(dividend), dvs = labs(divisor), result = 0;
        int sign = ((dividend > 0) ^ (divisor > 0)) == 0 ? 1 : -1;
        while(dvd >= dvs) {
            long long temp = dvs, mul = 1;
            while(temp << 1 <= dvd) {
                temp <<= 1;
                mul <<= 1;
            }
            dvd -= temp;
            result += mul;
        }

        return sign * result;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> test_cases = {
        { { 10, 3 }, 3 },
        { { 7, -3 }, -2 },
        { { -2'147'483'648, -1 }, 2'147'483'647 },
        { { 1, 1 }, 1 },
        { { 2'147'483'647, 2 }, 1073741823 },
    };

    Solution solution;

    for (auto [args, ans] : test_cases)
        assert_m(solution.divide(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
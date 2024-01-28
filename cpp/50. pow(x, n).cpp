//
// Created by Rutvik Patel on 1/28/24.
//

#include "include.h"

// solution
class Solution {
public:
    double myPow(double x, int n) {
        double s = 1;
        s = (double)pow(x, n);
        return s ;
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<double, int>, double>> test_cases = {
        { { 2.00000, 10 }, 1024.00000 },
        { { 2.10000, 3 }, 9.26100 },
        { { 2.00000, -2 }, 0.25000 },
//        { { 1.0000000000001, -2147483648 }, 0.99979 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.myPow(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
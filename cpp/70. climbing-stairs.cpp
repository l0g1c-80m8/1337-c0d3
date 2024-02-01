//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int p_count = 0, count = 1;
        for (int idx = 2; idx <= n; ++idx) {
            int temp = count;
            count += p_count;
            p_count = temp;
        }

        return count + p_count;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, int>> test_cases = {
        { 2, 2 },
        { 3, 3 },
    };

    Solution solution;

    for(auto [args, ans] : test_cases)
        assert_m(solution.climbStairs(args) == ans, "Failed!");

    log("All testcases passed!");
}
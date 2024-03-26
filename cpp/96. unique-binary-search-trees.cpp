//
// Created by Rutvik Patel on 3/26/24.
//

#include "include.h"

// solution

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp (n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                dp[i] += dp[j] * dp[i - j - 1];

        return dp.back();
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {

    // solution verified on leetcode

    log("All testcases passed!");
}
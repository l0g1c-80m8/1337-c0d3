//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) std::swap(m, n);
        long long unique_paths = 1;

        for (int idx = 0; idx < n - 1; ++idx) {
            unique_paths *= (m + idx);
            unique_paths /= (idx + 1);
        }

        return unique_paths;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> test_cases = {
        { { 3, 7 }, 28 },
        { { 3, 2 }, 3 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.uniquePaths(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
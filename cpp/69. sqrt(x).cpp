//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
private:
    int search_sqrt(int l, int u, int t) {
        if (l > u) return u; // Change this line to return m instead of u

        int m = (l + u) / 2;
        long long sq = static_cast<long long>(m) * m;

        if (sq == t) return m;
        if (sq < t) return search_sqrt(m + 1, u, t);

        return search_sqrt(l, m - 1, t);
    }
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        return search_sqrt(0, x / 2, x);
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, int>> test_cases = {
        { 4, 2 },
        { 8, 2 },
        { 36, 6 },
        { 2147395599, 46339 },
    };

    Solution solution;

    for (auto [args, ans] : test_cases)
        assert_m(solution.mySqrt(args) == ans, "Failed!");

    log("All testcases passed!");
}
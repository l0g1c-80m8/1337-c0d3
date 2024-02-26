//
// Created by Rutvik Patel on 2/25/24.
//

#include "include.h"

// solution
class Solution {
private:
    int numDecodingsTopDown(std::string s, int index, std::vector<int>& memo) {
        if (index == s.length()) return 1;
        if (s[index] == '0') return 0;
        if (memo[index] != -1) return memo[index];

        int ways = numDecodingsTopDown(s, index + 1, memo);

        if (index + 1 < s.length() and (s[index] == '1' or (s[index] == '2' and s[index + 1] <= '6'))) {
            ways += numDecodingsTopDown(s, index + 2, memo);
        }

        memo[index] = ways;
        return ways;
    }
public:
    int numDecodings(std::string& s) {
        std::vector<int> memo(s.length(), -1);
        return numDecodingsTopDown(s, 0, memo);
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, int>> test_cases = {
        { "12", 2 },
        { "226", 3 },
        { "06", 0 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.numDecodings(args) == ans, "Failed!");

    log("All testcases passed!");
}
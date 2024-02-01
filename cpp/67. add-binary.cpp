//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    std::string addBinary(std::string s1, std::string s2) {
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());

        int maxSize = static_cast<int>(std::max(s1.size(), s2.size()));
        int carry = 0;
        std::string result;

        for (int idx = 0; idx < maxSize; ++idx) {
            int digit1 = idx < s1.size() ? s1[idx] - '0' : 0;
            int digit2 = idx < s2.size() ? s2[idx] - '0' : 0;
            int sum = digit1 + digit2 + carry;

            if (sum == 3) {
                result.push_back('1');
                carry = 1;
            } else if (sum == 2) {
                result.push_back('0');
                carry = 1;
            } else {
                result.push_back(static_cast<char>(sum + '0'));
                carry = 0;
            }
        }

        if (carry) result.push_back('1');

        std::reverse(result.begin(), result.end());

        return result;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, std::string>> test_cases = {
        { { "11", "1" }, "100"},
        { { "1010", "1011" }, "10101"},
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.addBinary(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
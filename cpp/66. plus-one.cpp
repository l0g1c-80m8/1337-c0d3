//
// Created by Rutvik Patel on 1/31/24.
//

#include "include.h"

// solution
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> result (digits.size(), 0);
        int remainder = 1;

        for (int idx = static_cast<int>(digits.size()) - 1; idx >= 0; --idx) {
            int sum = digits[idx] + remainder;
            remainder = sum > 9 ? 1 : 0;
            result[idx] = (sum % 10);
        }
        if (remainder == 1) result.insert(result.begin(), remainder);

        return result;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> test_cases = {
        { { 1, 2, 3 }, { 1, 2, 4 } },
        { { 4, 3, 2, 1 }, { 4, 3, 2, 2 } },
        { { 9 }, { 1, 0 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.plusOne(args) == ans, "Failed!");

    log("All testcases passed!");
}
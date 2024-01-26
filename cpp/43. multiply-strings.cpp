//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"

// solution

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        std::vector<int> res(num1.size() + num2.size(), 0);

        for (int idx_1 = num1.size() - 1; idx_1 >= 0; --idx_1) {
            for (int idx_2 = num2.size() - 1; idx_2 >= 0; --idx_2) {
                res[idx_1 + idx_2 + 1] += (num1[idx_1] - '0') * (num2[idx_2] - '0');
                res[idx_1 + idx_2] += res[idx_1 + idx_2 + 1] / 10;
                res[idx_1 + idx_2 + 1] %= 10;
            }
        }

        int idx = 0;
        std::string ans;
        while (res[idx] == 0) ++idx;
        while (idx < res.size()) ans += std::to_string(res[idx++]);

        return ans;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, std::string>> test_cases = {
        { { "2", "3" }, "6" },
        { { "123", "456" }, "56088" },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.multiply(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
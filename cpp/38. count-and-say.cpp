//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"
#include <unordered_map>

// solution

class Solution {
private:
    std::string generate_string(std::string s_string) {
        std::string n_string;
        int f_idx = 0;

        while (f_idx < s_string.size()) {
            int count = 0, s_idx = f_idx;
            while (s_idx < s_string.size() and s_string[f_idx] == s_string[s_idx]) {
                ++count;
                ++s_idx;
            }
            n_string += std::to_string(count) + s_string[f_idx];
            f_idx = s_idx;
        }

        return n_string;
    }
public:
    std::string countAndSay(int n) {
        std::string res = "1";

        if (n == 1) return res;

        for (int idx = 1; idx < n; ++idx)
            res = generate_string(res);

        return res;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, std::string>> test_cases = {
        { 1, "1" },
        { 4, "1211" },
        { 5, "111221" },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.countAndSay(args) == ans, "Failed!");

    log("All testcases passed!");
}
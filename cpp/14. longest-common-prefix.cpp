//
// Created by Rutvik Patel on 11/19/23.
//

#include "include.h"
#include <numeric>

// solution

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        auto max_prefix_len = std::accumulate(
            strs.begin(),
            strs.end(),
            std::numeric_limits<int>::max(),
            [](int acc, const std::string& s) {
                return std::min(acc, static_cast<int>(s.size()));
            }
        );

        int idx;
        for (idx = 0; idx < max_prefix_len; idx++) {
            char ch = strs[0][idx];
            if (!std::all_of(
                strs.begin(),
                strs.end(),
                [ch, idx](const std::string& s){ return s[idx] == ch; }
            ))
                break;
        }

        return strs[0].substr(0, idx);
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, std::string>> test_cases = {
        { { "flower", "flow", "flight" }, "fl" },
        { { "dog", "racecar", "car" }, "" },
    };

    Solution solution;

    for (auto [args, ans] : test_cases)
        assert_m(solution.longestCommonPrefix(args) == ans, "Failed!");

    log("All testcases passed!");
}
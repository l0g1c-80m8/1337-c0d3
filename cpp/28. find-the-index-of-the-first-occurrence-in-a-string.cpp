//
// Created by Rutvik Patel on 12/1/23.
//

#include "include.h"

// solution

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.size() < needle.size())
            return -1;

        for (int idx = 0; idx <= haystack.size() - needle.size(); ++idx) {
            bool match = true;
            for (int j_idx = 0; j_idx < needle.size(); ++j_idx) {
                if (needle.at(j_idx) != haystack.at(idx + j_idx)) {
                    match = false;
                    break;
                }
            }

            if (match)
                return idx;
        }

        return -1;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, int>> test_cases = {
        { { "sadbutsad", "sad" }, 0 },
        { { "leetcode", "leeto" }, -1 },
        { { "mississippi", "issip" }, 4 },
        { { "mississippi", "issipi" }, -1 },
        { { "a", "a" }, 0 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.strStr(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
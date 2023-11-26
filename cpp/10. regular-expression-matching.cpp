//
// Created by Rutvik Patel on 11/26/23.
//

#include "include.h"

// solution

class Solution {
private:
    enum MATCH_MODES { SINGLE_ANY, SINGLE_CHAR, MULTI_ANY, MULTI_CHAR };

    static std::vector<std::pair<MATCH_MODES, char>> extract_sub_patterns(std::string p) {
        std::vector<std::pair<MATCH_MODES, char>> sub_patterns;

        for (auto ch : p) {
            switch (ch) {
                case '.': {
                    sub_patterns.emplace_back(SINGLE_ANY, ch);
                    break;
                }
                case '*': {
                    auto prev_entry = sub_patterns.back();
                    sub_patterns.pop_back();
                    sub_patterns.emplace_back(
                        prev_entry.second == '.' ? MULTI_ANY : MULTI_CHAR,
                        prev_entry.second
                    );
                    break;
                }
                default:
                    sub_patterns.emplace_back(SINGLE_CHAR, ch);
            }
        }
        return sub_patterns;
    }

public:
    bool isMatch(std::string s, std::string p) {
        int s_ptr = 0;
        for (auto& [mode, ch] : extract_sub_patterns(std::move(p))) {
            if (s_ptr >= s.size())
                return false;
            switch (mode) {
                case SINGLE_CHAR:
                    break;
                case SINGLE_ANY:
                    break;
                case MULTI_CHAR:
                    break;
                case MULTI_ANY:
                    break;
            }
        }

        return true;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> test_cases = {
        { { "aa", "a" }, false },
        { { "aa", "a*" }, true },
        { { "ab", ".*" }, false },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.isMatch(args.first, args.second) == ans, "Failed!");


    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 11/23/23.
//

#include "include.h"
#include <stack>
#include <unordered_map>

// solution

class Solution {
private:
    static std::unordered_map<char, bool> BRACKET_OPEN_MARKER;
    static std::unordered_map<char, char> BRACKET_MARKER_ASSOCIATION;
public:
    bool isValid(std::string s) {
        bool valid = true;
        std::stack<char> st;

        for (char ch : s) {
            if (BRACKET_OPEN_MARKER[ch]) st.push(ch);
            else if (st.empty() or BRACKET_MARKER_ASSOCIATION[ch] != st.top()) {
                valid = false;
                break;
            }
            else st.pop();
        }

        if (not st.empty()) {
            valid = false;
            while (not st.empty()) { st.pop(); }
        }

        return valid;
    }
};

std::unordered_map<char, bool> Solution::BRACKET_OPEN_MARKER = {
    { '(', true },
    { '[', true },
    { '{', true },
    { ')', false },
    { ']', false },
    { '}', false },
};

std::unordered_map<char, char> Solution::BRACKET_MARKER_ASSOCIATION = {
    { ')', '(' },
    { ']', '[' },
    { '}', '{' },
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, bool>> test_cases = {
        { "()", true },
        { "()[]{}", true },
        { "(]", false },
        { "[", false },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        assert_m(solution.isValid(args) == ans, "Failed!");
    }

    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 11/24/23.
//

#include "include.h"

// solution

class Solution {
private:
    void fill_combos(std::vector<std::string>& ans, int oc, int cc, std::string curr_combo) {
        if (cc < oc)
            return;
        if (oc < 0 or cc < 0)
            return;
        if (oc == 0 and cc == 0) {
            ans.push_back(curr_combo);
            return;
        }

        fill_combos(ans, oc - 1, cc, curr_combo + "(");
        fill_combos(ans, oc, cc - 1, curr_combo + ")");
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        fill_combos(ans, n + 0, n + 0, {});
        return ans;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, std::vector<std::string>>> test_cases = {
        { 3, { "((()))", "(()())", "(())()", "()(())", "()()()" } },
        { 1, { "()" } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.generateParenthesis(args) == ans, "Expired!");

    log("All testcases passed!");
}
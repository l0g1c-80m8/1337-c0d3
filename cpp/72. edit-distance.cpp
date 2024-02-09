//
// Created by Rutvik Patel on 2/2/24.
//

#include "include.h"

// solution
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> edit(word1.size() + 1, std::vector<int> (word2.size() + 1, 0));

        for (int r_idx = 1; r_idx < edit.size(); ++r_idx)
            edit[r_idx][0] = r_idx;

        for (int c_idx = 1; c_idx < edit[0].size(); ++c_idx)
            edit[0][c_idx] = c_idx;

        for (int r_idx = 1; r_idx < edit.size(); ++r_idx) {
            for (int c_idx = 1; c_idx < edit[0].size(); ++c_idx) {
                if (word1[r_idx - 1] == word2[c_idx - 1])
                    edit[r_idx][c_idx] = edit[r_idx - 1][c_idx - 1];
                else
                    edit[r_idx][c_idx] = 1 + std::min(
                        edit[r_idx][c_idx - 1],
                        std::min(edit[r_idx - 1][c_idx - 1], edit[r_idx - 1][c_idx])
                    );
            }
        }

        return edit.back().back();
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, int>> test_cases = {
        { { "horse", "ros" }, 3 },
        { { "intention", "execution" }, 5 },
    };

    Solution solution;

    for(auto& [args, ans] : test_cases)
        assert_m(solution.minDistance(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
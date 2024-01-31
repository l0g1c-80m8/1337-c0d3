//
// Created by Rutvik Patel on 1/30/24.
//

#include "include.h"

// solution
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if (s.empty()) return 0;

        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), ::isspace));
        s.erase(std::find_if_not(s.rbegin(), s.rend(), ::isspace).base(), s.end());

        auto lastSpace = std::find_if(s.rbegin(), s.rend(), ::isspace);

        if (lastSpace != s.rend()) return static_cast<int>(std::distance(s.rbegin(), lastSpace));
        else return static_cast<int>(s.size());
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, int>> test_cases = {
        { "Hello World", 5 },
        { "   fly me   to   the moon  ", 4 },
        { "luffy is still joyboy", 6 },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.lengthOfLastWord(args) == ans, "Failed!");

    log("All testcases passed!");
}
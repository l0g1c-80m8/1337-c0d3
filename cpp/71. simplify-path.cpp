//
// Created by Rutvik Patel on 2/1/24.
//

#include "include.h"

#include <numeric>
#include <sstream>

// solution
class Solution {
private:
    static const char PATH_DELIMITER = '/';

public:
    std::string simplifyPath(const std::string& path) {
        std::vector<std::string> tokens;
        std::istringstream pathStream(path);
        std::string token;

        while (std::getline(pathStream, token, PATH_DELIMITER)) {
            if (token.empty() or token == ".") continue;
            if (token == "..") {
                if (not tokens.empty()) tokens.pop_back();
            }
            else tokens.push_back(token + "/");
        }

        if (not tokens.empty()) tokens.back().pop_back();

        return "/" + std::accumulate(tokens.begin(), tokens.end(), std::string());
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        { "/home/", "/home" },
        { "/../", "/" },
        { "/home//foo/", "/home/foo" },
        { "/a/./b/../../c/", "/c" },
        { "/a/../../b/../c//.//", "/c" },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.simplifyPath(args) == ans, "Failed!");

    log("All testcases passed!");
}
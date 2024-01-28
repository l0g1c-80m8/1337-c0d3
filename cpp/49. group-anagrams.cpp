//
// Created by Rutvik Patel on 1/28/24.
//

#include "include.h"
#include <map>

// solution
class Solution {
private:
    static const int ALPHABET_SIZE = 26;

    [[nodiscard]] std::vector<int> get_signature(std::string s) const {
        std::vector<int> sig(ALPHABET_SIZE, 0);
        int offset = static_cast<int>('a');
        for (auto ch: s) ++sig[static_cast<int>(ch) - offset];
        return sig;
    }

public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::map<std::vector<int>, std::vector<std::string>> signature_to_string;

        for (auto &s: strs) {
            auto sig = get_signature(s);
            if (signature_to_string.contains(sig))
                signature_to_string[sig].push_back(s);
            else
                signature_to_string[sig] = {s};
        }

        std::vector<std::vector<std::string>> groups;
        std::transform(
            signature_to_string.begin(),
            signature_to_string.end(),
            std::back_inserter(groups),
            [](const std::pair<std::vector<int>, std::vector<std::string>>& element) {
                return element.second;
            }
        );
        return groups;
    }
};
// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>>> test_cases = {
        { { "eat", "tea", "tan", "ate", "nat", "bat" }, { { "tan", "nat" }, { "eat", "tea", "ate" }, { "bat" } } },
        { { "" }, { { "" } } },
        { { "a" }, { { "a" } } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.groupAnagrams(args) == ans, "Failed!");

    log("All testcases passed!");
}
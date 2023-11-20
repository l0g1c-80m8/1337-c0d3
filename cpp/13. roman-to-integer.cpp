//
// Created by Rutvik Patel on 11/19/23.
//

#include "include.h"
#include <numeric>
#include <unordered_map>

// solution

class Solution {
private:
    static std::unordered_map<char, int> ROMAN_VS_NUMERIC;
public:
    int romanToInt(std::string s) {
        std::string aug_str = s + "$";

        return std::reduce(aug_str.begin(), aug_str.end() - 1, 0, [&](int acc, char& ch) {
            return acc +
            (
                ROMAN_VS_NUMERIC[ch] *
                (ROMAN_VS_NUMERIC[ch] < ROMAN_VS_NUMERIC[*(std::next(&ch))] ? -1 : 1)
            );
        });
    }
};

std::unordered_map<char, int> Solution::ROMAN_VS_NUMERIC = {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 },
    { '$', std::numeric_limits<int>::min() },
};


// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, int>> test_cases = {
        { "III", 3 },
        { "LVIII", 58 },
        { "MCMXCIV", 1994 },
    };

    Solution solution;

    for (auto [args, ans] : test_cases)
        assert_m(solution.romanToInt(args) == ans, "Failed!");

    log("All test cases passed!");
}
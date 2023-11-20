//
// Created by Rutvik Patel on 11/20/23.
//

#include "include.h"
#include<set>

// solution

class Solution {
private:
    static std::unordered_map<char, std::vector<char>> DIGIT_VS_LETTERS;
public:
    std::set<std::string> letterCombinations(std::string digits) {
//        std::vector<std::string> letterCombinations(std::string digits) {
        std::set<std::string> combos = { "" };

        for (auto digit : digits) {
            auto letters = DIGIT_VS_LETTERS[digit];
            std::set<std::string> t_combos;

            for (auto& letter_combo :  combos)
                for (auto letter : letters)
                    t_combos.insert(letter_combo + letter);

            combos = std::move(t_combos);
        }
        combos.erase("");

        return combos;
//        return std::vector<std::string>(combos.begin(), combos.end());
    }
};

std::unordered_map<char, std::vector<char>> Solution::DIGIT_VS_LETTERS = {
    { '2', { 'a', 'b', 'c' } },
    { '3', { 'd', 'e', 'f' } },
    { '4', { 'g', 'h', 'i' } },
    { '5', { 'j', 'k', 'l' } },
    { '6', { 'm', 'n', 'o' } },
    { '7', { 'p', 'q', 'r', 's' } },
    { '8', { 't', 'u', 'v' } },
    { '9', { 'w', 'x', 'y', 'z' } },
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, std::set<std::string>>> test_cases = {
        { "23", { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" } },
        { "", {  } },
        { "2", { "a", "b", "c" } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.letterCombinations(args) == ans, "Failed!");

    log("All testcases passed!");
}
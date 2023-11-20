//
// Created by Rutvik Patel on 11/19/23.
//

#include "include.h"

#include <map>

// solution

class Solution {
private:
    static std::map<int, std::string> NUMS_TO_ROMAN;
    static std::vector<int> NUMS;

    static void process_number(int& num, std::string& target, std::size_t idx) {
        num -= NUMS[idx];
        target += NUMS_TO_ROMAN[NUMS[idx]];
    }
public:
    std::string intToRoman(int num) {
        std::string roman;

        while (num > 0) {
            std::input_iterator auto itr = std::ranges::find_if(
                NUMS.begin(),
                NUMS.end(),
                [num](int n){ return n <= num; }
            );
            if (itr != NUMS.end())
                process_number(num, roman, std::distance(NUMS.begin(), itr));
        }

        return roman;
    }
};

std::vector<int> Solution::NUMS = {
    1000,
    900, 500, 400, 100,
    90, 50, 40, 10,
    9, 5, 4, 1
};

std::map<int, std::string> Solution::NUMS_TO_ROMAN = {
    // single digits
    { Solution::NUMS[12], "I" },
    { Solution::NUMS[11], "IV" },
    { Solution::NUMS[10], "V" },
    { Solution::NUMS[9], "IX" },
    // double digits
    { Solution::NUMS[8], "X" },
    { Solution::NUMS[7], "XL" },
    { Solution::NUMS[6], "L" },
    { Solution::NUMS[5], "XC" },
    // triple digits
    { Solution::NUMS[4], "C" },
    { Solution::NUMS[3], "CD" },
    { Solution::NUMS[2], "D" },
    { Solution::NUMS[1], "CM" },
    // 1000
    { Solution::NUMS[0], "M" }
};

// main

//    Symbol       Value
//    I             1
//    V             5
//    X             10
//    L             50
//    C             100
//    D             500
//    M             1000

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, std::string>> test_cases = {
        { 3, "III" },
        { 58, "LVIII" },
        { 1994, "MCMXCIV" },
    };

    Solution solution;
    for (auto [num, roman] : test_cases) {
        assert_m(solution.intToRoman(num) == roman, "Failed!");
    }

    log("All test cases passed!");
}
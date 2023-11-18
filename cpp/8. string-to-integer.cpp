//
// Created by Rutvik Patel on 11/17/23.
//

#include "include.h"

#include <sstream>

//solution

class Solution {
public:
    int myAtoi(std::string s) {
        std::stringstream ss {s};
        char ch;
        int sign = 1;
        int number = 0;
        bool constrain_chars = false;
        char empty;

        ss >> std::noskipws;  // Set the noskipws manipulator to disable skipping whitespaces

        while (ss >> ch) {
            std::cout << number << std::endl;
            if (ch >= '0' and ch <= '9') {
                constrain_chars = true;
                int diff_digit = static_cast<int>(ch) - static_cast<int>('0');
                if (number > std::numeric_limits<int32_t>::max() / 10) {
                    number = sign < 0 ? std::numeric_limits<int32_t>::min() : std::numeric_limits<int32_t>::max();
                    sign = 1;
                    break;
                }
                else if (number < std::numeric_limits<int32_t>::min() / 10) {
                    number = std::numeric_limits<int32_t>::min();
                    sign = 1;
                    break;
                }
                else if (number == std::numeric_limits<int32_t>::max() / 10) {
                    int last_digit = std::abs((sign < 0 ?
                        std::numeric_limits<int32_t>::min() :
                        std::numeric_limits<int32_t>::max()) % 10);
                    std::cout << last_digit << "  " << diff_digit << "   ";
                    number = sign * number * 10 + sign * std::min(last_digit, diff_digit);
                    std::cout << number << "  ";
                    sign = 1;
                    std::cout << "yes";
                }
                else
                    number = number * 10 + diff_digit;
            }
            else if (constrain_chars) {
                break;
            }
            else if (ch == '+') {
                constrain_chars = true;
            }
            else if (ch == '-') {
                constrain_chars = true;
                sign *= -1;
            }
            else if (!constrain_chars and ch != ' ') {
                break;
            }
        }

        std::cout << sign * number << std::endl;
        return sign * number;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, int32_t>> test_cases = {
        {"00000-42a1234", 0},
        {"42", 42},
        {"   -42", -42},
        {"4193 with words", 4193},
        {"00042", 42},
        {"words and 987", 0},
        {"+1", 1},
        {"+42", 42},
        {"+-12", 0},
        {"   +0 123", 0},
        {"2147483646", 2'147'483'646},
        {"2147483647", 2'147'483'647},
        {"-2147483644", -2'147'483'644},
        {"-2147483648", -2'147'483'648},
        {"2147483648", 2'147'483'647},
        {"-2147483649", -2'147'483'648},
        {"21474836460", 21'474'836'47},
        {"-21474836482", -21'474'836'48},
    };

    Solution solution;

    for (auto [arg_str, int_res] : test_cases)
        assert_m(solution.myAtoi(arg_str) == int_res, "Failed!");

    log("All test cases passed!");
}
//
// Created by Rutvik Patel on 11/18/23.
//

#include "include.h"

// solution

class Solution {
public:
    bool isPalindrome(int x) {
        long rev_x = 0;
        long copy_x = x;
        while (copy_x > 0) {
            rev_x = rev_x * 10 + copy_x % 10;
            copy_x /= 10;
        }

        return x == rev_x;
    }
};


// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, bool>> test_cases = {
        {121, true},
        {-121, false},
        {10, false},
    };

    Solution solution;

    for (auto [num, res] : test_cases)
        assert_m(solution.isPalindrome(num) == res, "Failed!");

    log("All test cases passed!");
}
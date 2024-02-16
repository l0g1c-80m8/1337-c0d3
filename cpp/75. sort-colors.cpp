//
// Created by Rutvik Patel on 2/8/24.
//

#include "include.h"
#include <unordered_map>

// solution
class Solution {
private:
    static std::unordered_map<std::string, int> COLOR_TO_ID;
public:
    void sortColors(std::vector<int>& nums) {
        std::unordered_map<int, int> color_count = {
            { COLOR_TO_ID["RED"], 0 },
            { COLOR_TO_ID["WHITE"], 0 },
            { COLOR_TO_ID["BLUE"], 0 },
        };

        for (auto n : nums)
            ++color_count[n];

        int idx = 0, acc = 0;
        while (idx < acc + color_count[COLOR_TO_ID["RED"]]) nums[idx++] = COLOR_TO_ID["RED"];
        acc = idx;
        while (idx < acc + color_count[COLOR_TO_ID["WHITE"]]) nums[idx++] = COLOR_TO_ID["WHITE"];
        acc = idx;
        while (idx < acc + color_count[COLOR_TO_ID["BLUE"]]) nums[idx++] = COLOR_TO_ID["BLUE"];
    }
};

std::unordered_map<std::string, int> Solution::COLOR_TO_ID = {
    { "RED", 0 },
    { "WHITE", 1 },
    { "BLUE", 2 },
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> test_cases = {
        { { 2, 0, 2, 1, 1, 0 }, { 0, 0, 1, 1, 2, 2 } },
        { { 2, 0, 1 }, { 0, 1, 2 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases) {
        solution.sortColors(args);
        assert_m(args == ans, "Failed!");
    }

    log("All testcases passed!");
}
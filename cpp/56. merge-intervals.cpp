//
// Created by Rutvik Patel on 1/30/24.
//

#include "include.h"

// solution
class Solution {
private:
    bool expand_overlap(std::pair<int, int>& i1, std::pair<int, int>&& i2) {
        if (i1.second >= i2.first) {
            i1 = { std::min(i1.first, i2.first), std::max(i1.second, i2.second) };
            return true;
        }
        return false;
    }
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        std::sort(
            intervals.begin(),
            intervals.end(),
            [](auto& i1, auto& i2) { return i1[0] < i2[0]; }
        );

        std::vector<std::vector<int>> merged_intervals;

        std::pair<int, int> interval = { intervals[0][0], intervals[0][1] };
        for (auto & curr_interval : intervals) {
            if (not expand_overlap(interval, { curr_interval[0], curr_interval[1] })) {
                merged_intervals.push_back({ interval.first, interval.second });
                interval = { curr_interval[0], curr_interval[1] };
            }
        }

        merged_intervals.push_back({ interval.first, interval.second });

        return merged_intervals;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> test_cases = {
        { { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } }, { { 1, 6 }, { 8, 10 }, { 15, 18 } } },
        { { { 1, 4 }, { 4, 5 } }, { { 1, 5 } } },
        { { { 1, 4 }, { 2, 3 } }, { { 1, 4 } } },
        { { { 1, 4 }, { 0, 2 }, { 3, 5 } }, { { 0, 5 } } },
        { { { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 }, { 1, 10 } }, { { 1, 10 } } },
        { {  }, {  } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.merge(args) == ans, "Failed!");

    log("All testcases passed!");
}
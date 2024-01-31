//
// Created by Rutvik Patel on 1/30/24.
//

#include "include.h"

// solution
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& new_interval) {
        if (intervals.empty()) return {new_interval};

        std::sort(
            intervals.begin(),
            intervals.end(),
            [](auto& i1, auto& i2) { return i1[0] < i2[0]; }
        );

        std::vector<std::vector<int>> inserted_intervals;
        int idx = 0;

        while (idx < intervals.size() && intervals[idx][1] < new_interval[0]) {
            inserted_intervals.push_back(intervals[idx]);
            ++idx;
        }

        while (idx < intervals.size() && new_interval[1] >= intervals[idx][0]) {
            new_interval[0] = std::min(new_interval[0], intervals[idx][0]);
            new_interval[1] = std::max(new_interval[1], intervals[idx][1]);
            ++idx;
        }

        inserted_intervals.push_back(new_interval);

        while (idx < intervals.size()) {
            inserted_intervals.push_back(intervals[idx]);
            ++idx;
        }

        return inserted_intervals;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<std::vector<int>>, std::vector<int>>, std::vector<std::vector<int>>>> test_cases = {
        { { { { 1, 3 }, { 6, 9 } }, { 2, 5 } }, { { 1, 5 }, { 6, 9 } } },
        { { { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 4, 8 } }, { 1, 2 } }, { { 3, 10 }, { 12, 16 } } },
    };

    Solution solution;

    for(auto & [args, ans] : test_cases)
        assert_m(solution.insert(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
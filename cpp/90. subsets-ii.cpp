//
// Created by Rutvik Patel on 2/24/24.
//

#include "include.h"

// solution
class Solution {
private:
    void generateSubsets(const std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start or nums[i] != nums[i - 1]) {
                current.push_back(nums[i]);
                generateSubsets(nums, i + 1, current, result);
                current.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<std::vector<int>>>> test_cases = {
        { { 1, 2, 2 }, { { }, { 1 }, { 1, 2 }, { 1, 2, 2 }, { 2 }, { 2, 2 } } },
        { { 0 }, { { }, { 0 } } },
    };

    Solution solution;

    for(auto& [args, ans] : test_cases)
        assert_m(solution.subsetsWithDup(args) == ans, "Failed!");

    log("All testcases passed!");
}
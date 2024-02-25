//
// Created by Rutvik Patel on 2/24/24.
//

#include "include.h"

// solution
class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> gray_code(1 << n);

        std::transform(
            gray_code.begin(),
            gray_code.end(),
            gray_code.begin(),
            [idx = 0](int) mutable {
                int result = idx ^ (idx >> 1);
                idx++;
                return result;
            }
        );

        return gray_code;
    }
};


// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<int, std::vector<int>>> test_cases = {
        { 2, { 0, 1, 3, 2 } },
        { 1, { 0, 1 } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.grayCode(args) == ans, "Failed!");

    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 2/25/24.
//

#include "include.h"

// solution
class Solution {
private:
    void get_addresses(
        std::vector<std::string>& addresses,
        std::string address,
        const std::string& s,
        int c_idx,
        int n_ints
    ) {
        if (n_ints > 4) return;
        if (n_ints == 4 and c_idx == s.size()) {
            address.pop_back();
            addresses.push_back(address);
            return;
        }

        for (int idx = 1; idx <= 3 and c_idx + idx <= s.size(); ++idx) {
            auto i_string = s.substr(c_idx, idx);
            if (i_string[0] == '0' and i_string.size() > 1) break;
            if (std::stoi(i_string) < 256)
                get_addresses(addresses, address + i_string + ".", s, c_idx + idx, n_ints + 1);
        }
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> addresses;
        get_addresses(addresses, "", s, 0, 0);
        return addresses;
    }
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::string, std::vector<std::string>>> test_cases = {
        { "25525511135", { "255.255.11.135", "255.255.111.35" } },
        { "0000", { "0.0.0.0" } },
        { "101023", { "1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3" } },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.restoreIpAddresses(args) == ans, "Failed!");

    log("All testcases passed!");
}
//
// Created by Rutvik Patel on 1/25/24.
//

#include "include.h"
#include <unordered_set>

// solution

class Solution {
private:
    static bool isValidRow(std::vector<std::vector<char>>& board, int row) {
        std::unordered_set<char> bin;

        for (auto ch : board[row]) {
            if (ch == '.') continue;
            if (bin.contains(ch)) return false;
            bin.insert(ch);
        }

        return true;
    }

    static bool isValidCol(std::vector<std::vector<char>>& board, int col) {
        std::unordered_set<char> bin;

        for (auto& row : board) {
            if (row[col] == '.') continue;
            if (bin.contains(row[col])) return false;
            bin.insert(row[col]);
        }

        return true;
    }

    static bool isValidBox(std::vector<std::vector<char>>& board, int row, int col) {
        std::unordered_set<char> bin;

        for (int r_idx = row; r_idx < row + 3; ++r_idx) {
            for (int c_idx = col; c_idx < col + 3; ++c_idx) {
                if (board[r_idx][c_idx] == '.') continue;
                if (bin.contains(board[r_idx][c_idx])) return false;
                bin.insert(board[r_idx][c_idx]);
            }
        }

        return true;
    }
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (not isValidRow(board, i)) return false;
            if (not isValidCol(board, i)) return false;
            if (not isValidBox(board, 3 * (i / 3), 3 * (i % 3))) return false;
        }
        return true;
    }
};

// main

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<char>>, bool>> test_cases = {
        { {
              { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
              { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
              { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
              { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
              { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
              { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
              { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
              { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
              { '.', '.', '.', '.', '8', '.', '.', '7', '9' },
          }, true },
        { {
            { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' },
        }, false }
    };

    Solution solution;

    for(auto& [args, ans] : test_cases)
        assert_m(solution.isValidSudoku(args) == ans, "Failed!");

    log("All testcases passed!");
}
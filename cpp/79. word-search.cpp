//
// Created by Rutvik Patel on 2/16/24.
//

#include "include.h"

// solution
class Solution {
private:
    static std::vector<std::pair<int, int>> NEIGHBOR_OFFSETS;

    std::vector<std::pair<int, int>> get_neighbors(const std::vector<std::vector<char>>& board, std::pair<int, int> pose) {
        std::vector<std::pair<int, int>> neighbor_poses;

        std::transform(
            NEIGHBOR_OFFSETS.begin(),
            NEIGHBOR_OFFSETS.end(),
            std::back_inserter(neighbor_poses),
            [&pose](const std::pair<int, int>& offset) {
                return std::make_pair(pose.first + offset.first, pose.second + offset.second);
            }
        );

        neighbor_poses.erase(
            std::remove_if(
                neighbor_poses.begin(),
                neighbor_poses.end(),
                [&board](const std::pair<int, int>& n_pose) {
                    return n_pose.first < 0 or
                    n_pose.second < 0 or
                    n_pose.first >= board.size() or
                    n_pose.second >= board[0].size();
                }
            ),
            neighbor_poses.end()
        );

        return neighbor_poses;
    }

    bool search(
        std::vector<std::vector<char>>& board,
        std::vector<std::vector<bool>>& visited,
        std::pair<int, int> pose,
        std::string& word,
        int char_idx
    ) {
        if (char_idx == word.size()) return true;
        if (visited[pose.first][pose.second] or board[pose.first][pose.second] != word[char_idx])
            return false;

        visited[pose.first][pose.second] = true;

        auto n_poses = get_neighbors(board, pose);
        if (n_poses.size() == 0 and char_idx == word.size() - 1) return true;
        for (auto& n_pose : n_poses)
            if (search(board, visited, n_pose, word, char_idx + 1))
                return true;

        visited[pose.first][pose.second] = false;
        return false;
    }
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.empty()) return false;

        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        for (int r_idx = 0; r_idx < board.size(); ++r_idx)
            for (int c_idx = 0; c_idx < board[r_idx].size(); ++c_idx)
                if (search(board, visited, {r_idx, c_idx}, word, 0))
                    return true;

        return false;
    }
};

std::vector<std::pair<int, int>> Solution::NEIGHBOR_OFFSETS = {
    { -1, 0 },  // up - prev row, same col
    { 1, 0 },   // down - next row, same col
    { 0, -1 },  // left - same row, prev col
    { 0, 1 },   // right - same row, next col
};

// main
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<std::vector<char>>, std::string>, bool>> test_cases = {
        { { { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } }, "ABCCED" }, true },
        { { { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } }, "SEE" }, true },
        { { { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } }, "ABCB" }, false },
        { { { { 'a' } }, "a" }, true },
        { { {
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
            }, "aaaaaaaaaaaaaa" }, true },
        { { {
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
                { 'a', 'a', 'a', 'a', 'a', 'a' },
            }, "aaaaaaaaaaaaaA" }, false },
    };

    Solution solution;

    for (auto& [args, ans] : test_cases)
        assert_m(solution.exist(args.first, args.second) == ans, "Failed!");

    log("All testcases passed!");
}
from typing import List
from collections import defaultdict


# lc sol start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_map = defaultdict(set)
        col_map = defaultdict(set)
        box_map = defaultdict(set)

        for r_idx in range(9):
            for c_idx in range(9):
                ch = board[r_idx][c_idx]
                if ch == '.':
                    continue

                is_valid = True
                if ch in row_map[r_idx]:
                    is_valid &= False
                if ch in col_map[c_idx]:
                    is_valid &= False
                if ch in box_map[(r_idx // 3, c_idx // 3)]:
                    is_valid &= False

                if not is_valid:
                    return False

                row_map[r_idx].add(ch)
                col_map[c_idx].add(ch)
                box_map[(r_idx // 3, c_idx // 3)].add(ch)

        return True


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [
            ([
                 ["5", "3", ".", ".", "7", ".", ".", ".", "."],
                 ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                 [".", "9", "8", ".", ".", ".", ".", "6", "."],
                 ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                 ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                 ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                 [".", "6", ".", ".", ".", ".", "2", "8", "."],
                 [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                 [".", ".", ".", ".", "8", ".", ".", "7", "9"]
             ],),
            ([
                 ["8", "3", ".", ".", "7", ".", ".", ".", "."],
                 ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                 [".", "9", "8", ".", ".", ".", ".", "6", "."],
                 ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                 ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                 ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                 [".", "6", ".", ".", ".", ".", "2", "8", "."],
                 [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                 [".", ".", ".", ".", "8", ".", ".", "7", "9"]
             ],)
        ],
        'outputs': [True, False],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.isValidSudoku(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

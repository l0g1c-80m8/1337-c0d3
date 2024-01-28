from typing import List
from copy import deepcopy


# lc sol start
class Solution:
    def rotate(self, orig_matrix: List[List[int]]) -> List[List[int]]:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix = deepcopy(orig_matrix)
        n_rows, n_cols = len(matrix), len(matrix[0])

        for r_idx in range(n_rows):
            for c_idx in range(r_idx, n_cols):
                matrix[r_idx][c_idx], matrix[c_idx][r_idx] = matrix[c_idx][r_idx], matrix[r_idx][c_idx]

        for row in matrix:
            for idx in range(n_cols // 2):
                row[idx], row[n_cols - idx - 1] = row[n_cols - idx - 1], row[idx]

        return matrix


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([[1, 2, 3], [4, 5, 6], [7, 8, 9]],),
                   ([[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]],)],
        'outputs': [[[7, 4, 1], [8, 5, 2], [9, 6, 3]], [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.rotate(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

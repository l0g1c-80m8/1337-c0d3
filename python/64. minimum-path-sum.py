from typing import List


# lc sol start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n_rows, n_cols = len(grid), len(grid[0])

        for row in range(1, n_rows):
            grid[row][0] += grid[row - 1][0]

        for col in range(1, n_cols):
            grid[0][col] += grid[0][col - 1]

        for row in range(1, n_rows):
            for col in range(1, n_cols):
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1])

        return grid[-1][-1]

# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([[1, 3, 1], [1, 5, 1], [4, 2, 1]],), ([[1, 2, 3], [4, 5, 6]],)],
        'outputs': [7, 12],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.minPathSum(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

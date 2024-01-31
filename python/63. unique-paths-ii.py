from typing import List


# lc sol start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        r, c = len(obstacleGrid), len(obstacleGrid[0])

        obstacleGrid[0][0] = 1 - obstacleGrid[0][0]

        for i in range(1, r):
            obstacleGrid[i][0] = obstacleGrid[i - 1][0] * (1 - obstacleGrid[i][0])

        for i in range(1, c):
            obstacleGrid[0][i] = obstacleGrid[0][i - 1] * (1 - obstacleGrid[0][i])

        for i in range(1, r):
            for j in range(1, c):
                obstacleGrid[i][j] = (obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]) * (1 - obstacleGrid[i][j])

        return obstacleGrid[-1][-1]


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([[0, 0, 0], [0, 1, 0], [0, 0, 0]],), ([[0, 1], [0, 0]],)],
        'outputs': [2, 1],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.uniquePathsWithObstacles(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

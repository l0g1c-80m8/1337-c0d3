from typing import List


# lc sol start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        down, right = m - 1, n - 1
        total = down + right

        dp = [1] * (total + 1)

        for idx in range(1, total + 1):
            dp[idx] = idx * dp[idx - 1]

        return dp[-1] // (dp[down] * dp[right])


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [(3, 7), (3, 2)],
        'outputs': [28, 3],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.uniquePaths(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

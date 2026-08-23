# lc solution start
class Solution:
    _MAX_INT = 2 ** 31 - 1

    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        x = abs(x)
        res = 0
        boundary = self._MAX_INT // 10

        while x != 0:
            digit = x % 10
            x //= 10

            if res > boundary or res == boundary and digit > 7:
                return 0

            res = (res * 10) + digit

        return res * sign
# lc solution end


def main() -> None:
    test_cases = {
        'inputs': [(123, ), (-123, ), (120, ), (0, )],
        'outputs': [321, -321, 21, 0]
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        result = solution.reverse(*args)
        expected = test_cases['outputs'][idx]
        assert result == expected, (
            f"Test case {idx} failed: expected {expected}, got {result}"
        )

    print("All test cases passed!")


if __name__ == '__main__':
    main()

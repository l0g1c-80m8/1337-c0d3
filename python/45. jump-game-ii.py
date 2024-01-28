import sys
from typing import List


# lc sol start
class Solution:
    def jump(self, nums: List[int]) -> int:
        distance = len(nums)
        min_jumps = [sys.maxsize] * distance
        min_jumps[0] = 0

        for start in range(distance):
            for jumpStep in range(start, min(distance, start + nums[start] + 1)):
                min_jumps[jumpStep] = min(min_jumps[jumpStep], 1 + min_jumps[start])

        return min_jumps[-1]

# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([2, 3, 1, 1, 4],), ([2, 3, 0, 1, 4],)],
        'outputs': [2, 2],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.jump(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

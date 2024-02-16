from collections import defaultdict
from typing import List


# lc sol start
class Solution:
    COLOR_TO_ID = {
        'RED': 0,
        'WHITE': 1,
        'BLUE': 2,
    }

    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        color_count = defaultdict(int)

        for n in nums:
            color_count[n] += 1

        acc = 0
        for idx in range(color_count[self.COLOR_TO_ID['RED']]):
            nums[acc + idx] = self.COLOR_TO_ID['RED']
        acc += color_count[self.COLOR_TO_ID['RED']]
        for idx in range(color_count[self.COLOR_TO_ID['WHITE']]):
            nums[acc + idx] = self.COLOR_TO_ID['WHITE']
        acc += color_count[self.COLOR_TO_ID['WHITE']]
        for idx in range(color_count[self.COLOR_TO_ID['BLUE']]):
            nums[acc + idx] = self.COLOR_TO_ID['BLUE']


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([2, 0, 2, 1, 1, 0],), ([2, 0, 1],)],
        'outputs': [[0, 0, 1, 1, 2, 2], [0, 1, 2]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        solution.sortColors(*args)
        assert args[0] == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {args[0]}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

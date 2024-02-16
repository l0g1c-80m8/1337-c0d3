from itertools import chain, combinations
from typing import List


# lc sol start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return list(map(list, chain.from_iterable(combinations(nums, r) for r in range(len(nums) + 1))))

# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([1, 2, 3],), ([0],), ([],)],
        'outputs': [[[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]], [[], [0]], [[]]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.subsets(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

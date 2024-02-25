from itertools import chain, combinations
from typing import List


# lc sol start
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        return list(map(list, set(chain.from_iterable(combinations(nums, r) for r in range(len(nums) + 1)))))

    # the following solution is also correct and is written without using build in functions
    # def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
    #     res = [[]]
    #     nums.sort()
    #     for i in range(len(nums)):
    #         if i == 0 or nums[i] != nums[i - 1]:
    #             l = len(res)
    #         for j in range(len(res) - l, len(res)):
    #             res.append(res[j] + [nums[i]])
    #     return res


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([1, 2, 2],), ([0],)],
        'outputs': [[[], [1], [2], [1, 2], [2, 2], [1, 2, 2]], [[], [0]]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.subsetsWithDup(*args)
        assert sorted(op) == sorted(test_cases['outputs'][idx]), \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

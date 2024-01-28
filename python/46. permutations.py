from typing import List


# lc sol start
class Solution:
    result = []

    def solve(self, nums: List[int], curr_nums: List[int]) -> None:
        if len(nums) == 0:
            self.result.append(curr_nums)
            return
        for idx in range(len(nums)):
            self.solve(nums[0: idx] + nums[idx + 1:], curr_nums + [nums[idx]])
        return

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.result = []
        self.solve(nums, [])
        return self.result


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([1, 2, 3],), ([0, 1],), ([1],)],
        'outputs': [[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]], [[0, 1], [1, 0]], [[1]]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.permute(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

from typing import List


# lc sol start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        distance = len(nums)
        maxPos = 0
        i = 0
        while i <= maxPos:
            maxPos = max(maxPos, i + nums[i])
            if maxPos >= distance - 1:
                return True
            i += 1

        return False


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([2, 3, 1, 1, 4],), ([3, 2, 1, 0, 4],)],
        'outputs': [True, False],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.canJump(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

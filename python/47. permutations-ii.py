from typing import List


# lc sol start
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        length = len(nums)

        def solve(idx, currNums):
            if idx == length:
                result.append(currNums)
                return

            duplicate_idx = currNums.index(nums[idx]) if nums[idx] in currNums else idx

            for insertIdx in range(duplicate_idx + 1):
                solve(idx + 1, currNums[: insertIdx] + [nums[idx]] + currNums[insertIdx:])

        solve(0, [])
        return result


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([1, 1, 2],), ([1, 2, 3],)],
        'outputs': [
            [[2, 1, 1], [1, 2, 1], [1, 1, 2]],
            [[3, 2, 1], [2, 3, 1], [2, 1, 3], [3, 1, 2], [1, 3, 2], [1, 2, 3]]
        ],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.permuteUnique(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

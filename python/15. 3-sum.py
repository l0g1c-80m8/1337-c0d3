from typing import List, Tuple


# lc sol start
class Solution:
    def threeSum(self, nums: List[int]) -> List[Tuple[int, int, int]]:
        nums.sort()
        triples = set()

        for f_idx in range(len(nums)):
            start_idx, end_idx = f_idx + 1, len(nums) - 1

            while (start_idx < end_idx):
                if nums[start_idx] + nums[end_idx] + nums[f_idx] > 0:
                    end_idx -= 1
                elif nums[start_idx] + nums[end_idx] + nums[f_idx] < 0:
                    start_idx += 1
                else:
                    triples.add((nums[f_idx], nums[start_idx], nums[end_idx]))
                    start_idx += 1

        return list(triples)
# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([-1, 0, 1, 2, -1, -4],), ([0, 1, 1],), ([0, 0, 0],), ([-1, 0, 1, 0],), ([-2, 0, 1, 1, 2],)],
        'outputs': [[(-1, -1, 2), (-1, 0, 1)], [], [(0, 0, 0)], [(-1, 0, 1)], [(-2, 0, 2), (-2, 1, 1)]]
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.threeSum(*args)
        assert set(op) == set(test_cases['outputs'][idx]), \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

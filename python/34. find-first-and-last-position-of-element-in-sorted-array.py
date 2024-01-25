from typing import List


# lc sol start
class Solution:
    def __init__(self):
        pass

    def _binary_search(self, nums: List[int], target: int, s_idx: int, e_idx: int) -> int:
        if s_idx > e_idx:
            return -1

        m_idx = (s_idx + e_idx) // 2

        if target == nums[m_idx]:
            return m_idx

        if target < nums[m_idx]:
            return self._binary_search(nums, target, s_idx, m_idx - 1)

        return self._binary_search(nums, target, m_idx + 1, e_idx)

    def _get_hit_range(self, nums: List[int], target: int, h_idx: int):
        s_idx, e_idx = h_idx, h_idx

        while s_idx >= 0 and nums[s_idx] == target:
            s_idx -= 1

        while e_idx < len(nums) and nums[e_idx] == target:
            e_idx += 1

        return [s_idx + 1, e_idx - 1]

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        h_idx = self._binary_search(nums, target, 0, len(nums) - 1)
        if h_idx == -1:
            return [-1, -1]
        return self._get_hit_range(nums, target, h_idx)

# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([5, 7, 7, 8, 8, 10], 8), ([5, 7, 7, 8, 8, 10], 6), ([], 0), ([1], 1)],
        'outputs': [[3, 4], [-1, -1], [-1, -1], [0, 0]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.searchRange(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

from typing import List


# lc sol start
class Solution:
    @staticmethod
    def get_area(height: List[int], start_idx: int, end_idx: int) -> int:
        return (end_idx - start_idx) * min(height[start_idx], height[end_idx])

    def maxArea(self, height: List[int]) -> int:
        start_idx, end_idx = 0, len(height) - 1
        max_area = float('-inf')

        while start_idx < end_idx:
            max_area = max(max_area, self.get_area(height, start_idx, end_idx))

            if height[start_idx] < height[end_idx]:
                start_idx += 1
            else:
                end_idx -= 1

        return max_area


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([1, 8, 6, 2, 5, 4, 8, 3, 7], ), ([1, 1], )],
        'outputs': [49, 1]
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.maxArea(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

from typing import List


# lc sol start
class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        first, last = 0, length - 1
        left_max, right_max = height[first], height[last]
        capacity = 0

        while first < last:
            if height[first] < height[last]:
                first += 1
                left_max = max(left_max, height[first])
                capacity += left_max - height[first]
            else:
                last -= 1
                right_max = max(right_max, height[last])
                capacity += right_max - height[last]

        return capacity


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],), ([4, 2, 0, 3, 2, 5],)],
        'outputs': [6, 9],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.trap(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

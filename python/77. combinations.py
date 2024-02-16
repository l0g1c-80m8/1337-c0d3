from itertools import combinations
from typing import List


# lc sol start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(map(list, combinations(range(1, n + 1), k)))

# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [(4, 2), (1, 1), (4, 3)],
        'outputs': [
            [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]],
            [[1]],
            [[1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4]]
        ],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.combine(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

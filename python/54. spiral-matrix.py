from typing import List


# lc sol start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        row_start, row_end = 0, len(matrix) - 1
        col_start, col_end = 0, len(matrix[0]) - 1

        result = []

        while row_start <= row_end and col_start <= col_end:
            result.extend(matrix[row_start][col_start: col_end + 1])
            row_start += 1

            for idx in range(row_start, row_end + 1):
                result.append(matrix[idx][col_end])
            col_end -= 1

            if row_start <= row_end:
                for idx in range(col_end, col_start - 1, -1):
                    result.append(matrix[row_end][idx])
                row_end -= 1

            if col_start <= col_end:
                for idx in range(row_end, row_start - 1, -1):
                    result.append(matrix[idx][col_start])
                col_start += 1

        return result


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [([[1, 2, 3], [4, 5, 6], [7, 8, 9]],), ([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]],)],
        'outputs': [[1, 2, 3, 6, 9, 8, 7, 4, 5], [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.spiralOrder(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

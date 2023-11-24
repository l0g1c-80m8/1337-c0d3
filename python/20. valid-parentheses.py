from collections import deque


# lc sol start
class Solution:
    PAIRS = {
        '}': '{',
        ')': '(',
        ']': '[',
    }
    OPENING_MARKERS = {'(', '{', '['}

    def isValid(self, s: str) -> bool:
        stack = deque()

        for char in s:
            if char in self.OPENING_MARKERS:
                stack.append(char)
            else:
                if len(stack) == 0:
                    return False
                popped = stack.pop()
                if popped != self.PAIRS[char]:
                    return False

        return len(stack) == 0


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [("(",), ("()[]{}",), ("(]",), ("[",)],
        'outputs': [True, True, False, False]
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.isValid(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

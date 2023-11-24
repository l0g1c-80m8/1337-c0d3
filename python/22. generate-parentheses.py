from typing import List


# lc sol start
class Solution:
    result = []

    def solve(self, oc: int, cc: int, currCombo: List[str]) -> None:
        if cc < oc:
            return
        if oc < 0 or cc < 0:
            return

        if cc == oc == 0:
            self.result.append(''.join(currCombo))
            return

        self.solve(oc - 1, cc, currCombo + ['('])
        self.solve(oc, cc - 1, currCombo + [')'])

    def generateParenthesis(self, n: int) -> List[str]:
        self.result = []
        self.solve(n + 0, n + 0, [])
        return self.result



# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [(3,), (1,)],
        'outputs': [["((()))", "(()())", "(())()", "()(())", "()()()"], ["()"]]
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.generateParenthesis(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

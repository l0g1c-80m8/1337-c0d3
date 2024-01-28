from collections import defaultdict
from typing import List, Any


# lc sol start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        letters_to_anagram_group = defaultdict(list)
        for string in strs:
            letters_to_anagram_group[tuple(sorted(string))].append(string)

        return list(letters_to_anagram_group.values())


# lc sol end


def main() -> None:
    test_cases = {
        'inputs': [(['eat', 'tea', 'tan', 'ate', 'nat', 'bat'],), ([''],), (['a'],)],
        'outputs': [[['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']], [['']], [['a']]],
    }

    solution = Solution()

    for idx, args in enumerate(test_cases['inputs']):
        op = solution.groupAnagrams(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

# lc sol start
def longest_palindrome(s):
    #  initialize
    n = len(s)
    dp = [[False] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = True

    #  dp based solution to find optimal length (between start and end index)
    max_len = 1
    for start in range(n - 1, -1, -1):
        for end in range(start + 1, n):
            if s[start] == s[end]:
                if end - start == 1 or dp[start + 1][end - 1]:
                    dp[start][end] = True
                    max_len = max(end - start + 1, max_len)

    #  search optimal value location in order of first to last
    for start in range(0, n - max_len + 1):
        if dp[start][start + max_len - 1]:
            return s[start:start + max_len]
# lc sol end


def main():
    test_cases = {
        'inputs': [('babad',), ('cbbd',), ('aacabdkacaa',), ('a',), ('aa',), ('ab',), ('abb',)],
        'outputs': ['bab', 'bb', 'aca', 'a', 'aa', 'a', 'bb']
    }

    for idx, args in enumerate(test_cases['inputs']):
        op = longest_palindrome(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for input {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

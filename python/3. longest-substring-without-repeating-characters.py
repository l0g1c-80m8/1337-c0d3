def length_of_longest_substring(s):
    start_idx, end_idx = 0, 0
    char_set = set()
    max_sub_str_len = 0

    while end_idx < len(s):
        if s[end_idx] not in char_set:
            char_set.add(s[end_idx])
            end_idx += 1
        else:
            max_sub_str_len = max(max_sub_str_len, end_idx - start_idx)
            char_set.remove(s[start_idx])
            start_idx += 1

    max_sub_str_len = max(max_sub_str_len, end_idx - start_idx)
    return max_sub_str_len


def main():
    test_cases = {
        ("abcabcbb", ): 3,
        ("bbbbb", ): 1,
        ("pwwkew", ): 3
    }

    for args, op in test_cases.items():
        assert length_of_longest_substring(*args) == op, f"expected output {op} for input {args}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

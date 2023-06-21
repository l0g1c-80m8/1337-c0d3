def find_median_sorted_arrays(nums1, nums2):
    # find median of the two arrays
    # based on the values of the two medians, eliminate the halves of both the arrays
    # recursively prune the halves until the final median is obtained
    return 0


def main():
    test_cases = {
        ([1, 3], [2]): 2.0,
        ([1, 2], [3, 4]): 2.5,
    }

    for args, op in test_cases.items():
        assert find_median_sorted_arrays(*args) == op, f"expected output {op} for arrays {args}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

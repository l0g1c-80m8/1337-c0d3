# lc sol start
def find_median_sorted_arrays(nums1, nums2):
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1

    len1, len2 = len(nums1), len(nums2)
    min_idx, max_idx, half_len = 0, len1, (len1 + len2 + 1) // 2

    while min_idx <= max_idx:
        i = (min_idx + max_idx) // 2
        j = half_len - i

        if i < len1 and nums2[j - 1] > nums1[i]:
            min_idx = i + 1
        elif i > 0 and nums1[i - 1] > nums2[j]:
            max_idx = i - 1
        else:
            if i == 0:
                max_left = nums2[j - 1]
            elif j == 0:
                max_left = nums1[i - 1]
            else:
                max_left = max(nums1[i - 1], nums2[j - 1])

            if (len1 + len2) % 2 == 1:
                return float(max_left)

            if i == len1:
                min_right = nums2[j]
            elif j == len2:
                min_right = nums1[i]
            else:
                min_right = min(nums1[i], nums2[j])

            return (max_left + min_right) / 2.0


# lc sol end


def main():
    test_cases = {
        'inputs': [([1, 3], [2]), ([1, 2], [3, 4])],
        'outputs': [2.0, 2.5]
    }

    for idx, args in enumerate(test_cases['inputs']):
        op = find_median_sorted_arrays(*args)
        assert op == test_cases['outputs'][idx], \
            f"expected output {test_cases['outputs'][idx]} for arrays {args}, got {op}"

    print('all sample test cases passed successfully!')


if __name__ == '__main__':
    main()

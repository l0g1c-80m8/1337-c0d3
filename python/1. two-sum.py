def two_sum(nums, target):
    diffIdx = dict()
    for idx in range(len(nums)):
        if nums[idx] in diffIdx:
            return [diffIdx[nums[idx]], idx]
        else:
            diffIdx[target - nums[idx]] = idx


def main():
    solution = two_sum([2, 7, 11, 15], 9)
    print('\nSolution: {}\n'.format(solution))


if __name__ == '__main__':
    main()

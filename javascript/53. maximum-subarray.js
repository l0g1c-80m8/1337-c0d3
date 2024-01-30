/**
 * @param {number[]} nums
 * @return {number}
 */
const maxSubArray = function(nums) {
    let maxSoFar = nums[0];
    let maxEndingHere = 0;

    nums.forEach(num => {
        maxEndingHere += num;
        maxSoFar = maxSoFar < maxEndingHere ? maxEndingHere : maxSoFar;
        maxEndingHere = maxEndingHere < 0 ? 0 : maxEndingHere;
    });
    return maxSoFar;
};

const testcases = {
    'input': [[-2, 1, -3, 4, -1, 2, 1, -5, 4], [1], [5, 4, -1, 7, 8]],
    'output': [6, 1, 23, false, true],
};

testcases['input'].forEach((args, idx) => {
    const sol = maxSubArray(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
    console.log();
});

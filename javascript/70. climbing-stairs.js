/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

const getReverseBinaryArray = str => str.split('').reverse().map(digit => parseInt(digit));

/**
 * @param {number} n
 * @return {number}
 */


const climbStairs = function(n) {
    const arr = [];
    arr.length = n;
    let i = 0;

    for(i = 0; i < n; i++)
        arr[i] = i + 1;

    for(i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n - 1];
};

const testcases = {
    'input': [[2], [3]],
    'output': [2, 3],
};

testcases['input'].forEach((args, idx) => {
    const sol = climbStairs(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
    console.log();
});

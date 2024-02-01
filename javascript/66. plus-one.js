/**
 * @param {number[]} digits
 * @return {number[]}
 */
const plusOne = function(digits) {
    const revDigits = digits.reverse();
    let carry = true;
    const result = revDigits.map(digit => {
        if (carry) {
            if (digit === 9) {
                carry = true;
                return 0;
            }
            carry = false;
            return digit + 1;
        }
        return digit;
    });
    if (carry)
        result.push(carry);
    return result.reverse();
};

const testcases = {
    'input': [[1, 2, 3], [4, 3, 2, 1], [9]],
    'output': [[1, 2, 4], [4, 3, 2, 2], [1, 0]],
};

testcases['input'].forEach((args, idx) => {
    const sol = plusOne(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
    console.log();
});

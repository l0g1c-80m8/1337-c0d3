/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

const getReverseBinaryArray = str => str.split('').reverse().map(digit => parseInt(digit));

const addBinary = function(bin1, bin2) {
    const bstr1 = getReverseBinaryArray(bin1);
    const bstr2 = getReverseBinaryArray(bin2);

    const result = [];
    const endSize = Math.max(bstr1.length, bstr2.length);
    let i = 0;
    let carry = 0;

    for (i = 0; i < endSize; i++) {
        const digit1 = bstr1.length >= i + 1 ? bstr1[i] : 0;
        const digit2 = bstr2.length >= i + 1 ? bstr2[i] : 0;
        const sum = digit1 + digit2 + carry;

        if (sum === 3) {
            result.push(1);
            carry = 1;
        }
        else if (sum === 2) {
            result.push(0);
            carry = 1;
        }
        else {
            result.push(sum);
            carry = 0;
        }
    }
    if (carry)
        result.push(1);

    return result.map(digit => digit.toString()).reverse().join('');
};

const testcases = {
    'input': [["11", "1"], ["1010", "1011"]],
    'output': ["100", "10101"],
};

testcases['input'].forEach((args, idx) => {
    const sol = getReverseBinaryArray(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
    console.log();
});

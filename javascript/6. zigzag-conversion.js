// lc sol start

/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = (s, numRows) => {
    let result = '';
    for (let row = 0; row < numRows; row++) {
        const inc = Math.max((numRows - 1) * 2, 1);
        for (let idx = row; idx < s.length; idx += inc) {
            result += s[idx];
            const auxIdx = idx + inc - row * 2;
            if (row > 0 && row < numRows - 1 && auxIdx < s.length) {
                result += s[auxIdx];
            }
        }
    }
    return result;
};
// lc sol end

const testcases = {
    'input': [['PAYPALISHIRING', 3], ['PAYPALISHIRING', 4], ['A', 1]],
    'output': ['PAHNAPLSIIGYIR', 'PINALSIGYAHRPI', 'A'],
};

testcases['input'].forEach((args, idx) => {
    console.assert(
        convert(...args) === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${convert(...args)}`
    );
});

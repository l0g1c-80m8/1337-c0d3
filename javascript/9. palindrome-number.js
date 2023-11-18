/**
 * @param {number} x
 * @return {boolean}
 */
let isPalindrome = function(x) {
    let xReversed = 0;
    let xCopy = x;
    while(xCopy > 0) {
        xReversed *= 10;
        xReversed += xCopy % 10;
        xCopy = parseInt(xCopy / 10);
    }

    return xReversed === x;
};

const testcases = {
    'input': [[121], [-121], [10]],
    'output': [true, false, false],
};

testcases['input'].forEach((args, idx) => {
    console.assert(
        isPalindrome(...args) === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${isPalindrome(...args)}`
    );
});
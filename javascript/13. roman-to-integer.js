/**
 * @param {string} s
 * @return {number}
 */

const NUMERIC_VS_ROMAN = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
    '$': Number.MIN_SAFE_INTEGER
};

const romanToInt = function(s) {
    const aug_str = s + "$";

    return aug_str.split('').reduce((acc, char, idx) => {
        if (char === '$') {
            return acc
        }

        return acc + (NUMERIC_VS_ROMAN[char] * (
            NUMERIC_VS_ROMAN[char] < NUMERIC_VS_ROMAN[aug_str[idx + 1]] ? -1 : 1
        ));
    }, 0);
};

const testcases = {
    'input': [["III"], ["LVIII"], ["MCMXCIV"]],
    'output': [3, 58, 1994],
};

testcases['input'].forEach((args, idx) => {
    const sol = romanToInt(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
});

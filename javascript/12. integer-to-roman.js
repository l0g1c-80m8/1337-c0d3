/**
 * @param {number} num
 * @return {string}
 */

const NUMS = [
    1000,
    900, 500, 400, 100,
    90, 50, 40, 10,
    9, 5, 4, 1,
];

const NUM_TO_ROMAN = {
    [NUMS[12]]: "I",
    [NUMS[11]]: "IV",
    [NUMS[10]]: "V",
    [NUMS[9]]: "IX",
    [NUMS[8]]: "X",
    [NUMS[7]]: "XL",
    [NUMS[6]]: "L",
    [NUMS[5]]: "XC",
    [NUMS[4]]: "C",
    [NUMS[3]]: "CD",
    [NUMS[2]]: "D",
    [NUMS[1]]: "CM",
    [NUMS[0]]: "M",
};
const intToRoman = (num) => {
    let roman = "";

    while (num > 0) {
        const idx = NUMS.findIndex(n => num >= n);
        num -= NUMS[idx];
        roman += NUM_TO_ROMAN[NUMS[idx]];
    }

    return roman;
};


const testcases = {
    'input': [[3], [58], [1994]],
    'output': ["III", "LVIII", "MCMXCIV"],
};

testcases['input'].forEach((args, idx) => {
    const sol = intToRoman(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
});
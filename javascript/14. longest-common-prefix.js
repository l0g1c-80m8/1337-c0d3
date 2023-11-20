/**
 * @param {string[]} strs
 * @return {string}
 */
const longestCommonPrefix = strs => {
    const max_prefix_len = strs.reduce((acc, str) => {
        return Math.min(acc, str.length);
    }, Number.MAX_SAFE_INTEGER);

    const prefix_end_idx = Array(max_prefix_len)
        .fill(0)
        .map((_, idx) => idx)
        .find((ele, idx) => !strs.every(s => s.charAt(idx) === strs[0].charAt(idx)));

    return prefix_end_idx === undefined ? strs[0].substring(0, max_prefix_len) : strs[0].substring(0, prefix_end_idx);
};

const testcases = {
    'input': [[['flower', 'flow', 'flight'], ], [['dog', 'racecar', 'car'], ], [['a'], ], [['ab', 'a'], ]],
    'output': ['fl', '', 'a', 'a'],
};

testcases['input'].forEach((args, idx) => {
    const sol = longestCommonPrefix(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
    console.log();
});
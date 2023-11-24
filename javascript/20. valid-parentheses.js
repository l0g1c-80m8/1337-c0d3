// legacy implementation

// const BRACKET_TYPE_DEFINITION = {
//     round: {
//         type: 'ROUND',
//         opening: '(',
//         closing: ')',
//     },
//     curly: {
//         type: 'CURLY',
//         opening: '{',
//         closing: '}',
//     },
//     square: {
//         type: 'SQUARE',
//         opening: '[',
//         closing: ']',
//     },
//     DEFAULT: {
//         type: '',
//         opening: '',
//         closing: '',
//     },
// };
//
// const isStackEmpty = stack => (stack.length === 0);
//
// const pushInStack = (stack, char) => {
//     stack.push(char);
//     return true;
// }
//
// const popFromStack = (stack, char) => {
//     console.log(stack, char);
//     if (isStackEmpty(stack)) return false;
//     if ((stack.slice(-1)[0] || '') !== char) return false;
//     stack.pop();
//     return true;
// }
//
// const getHandleStackOps = stack => char => {
//     let result = false
//     switch(char) {
//         case BRACKET_TYPE_DEFINITION.round.opening:
//             result = pushInStack(stack, char);
//             break;
//         case BRACKET_TYPE_DEFINITION.round.closing:
//             result = popFromStack(stack, BRACKET_TYPE_DEFINITION.round.opening);
//             break;
//         case BRACKET_TYPE_DEFINITION.curly.opening:
//             result = pushInStack(stack, char);
//             break;
//         case BRACKET_TYPE_DEFINITION.curly.closing:
//             result = popFromStack(stack, BRACKET_TYPE_DEFINITION.curly.opening);
//             break;
//         case BRACKET_TYPE_DEFINITION.square.opening:
//             result = pushInStack(stack, char);
//             break;
//         case BRACKET_TYPE_DEFINITION.square.closing:
//             result = popFromStack(stack, BRACKET_TYPE_DEFINITION.square.opening);
//             break;
//         default:
//             result = false;
//     }
//     return result;
// };
//
// var isValid = function(s) {
//     const stack = [];
//
//     const handleStackOps = getHandleStackOps(stack);
//     const chars = s.split('');
//
//     const result = chars.every(handleStackOps);
//     return result && isStackEmpty(stack);
// };


const OPENING_MARKER_MAP = {
    '(': true,
    '[': true,
    '{': true,
    ')': false,
    ']': false,
    '}': false,
};

const BRACKET_MARKER_PAIR = {
    ')': '(',
    '}': '{',
    ']': '[',
};

/**
 * @param {string} s
 * @return {boolean}
 */
const isValid = s => {
    let valid = true;
    const stack = []

    for (const ch of s) {
        if (OPENING_MARKER_MAP[ch]) {
            stack.push(ch);
        }
        else if (stack.length === 0 || BRACKET_MARKER_PAIR[ch] !== stack[stack.length - 1]) {
            valid = false;
            break;
        }
        else {
            stack.pop();
        }
    }

    if (stack.length > 0) {
        valid = false;
    }

    return valid;
};

const testcases = {
    'input': [["()"], ["()[]{}"], ["(]"], ["["], ["{[]}"]],
    'output': [true, true, false, false, true],
};

testcases['input'].forEach((args, idx) => {
    const sol = isValid(...args);
    console.assert(
        sol === testcases['output'][idx],
        `Expected output ${testcases['output'][idx]} for input <${args}>, got ${sol}`
    );
    console.log();
});

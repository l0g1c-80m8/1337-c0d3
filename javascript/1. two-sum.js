/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const remainderVsIndex = {};
  const result = [];
  const indicesFinder = getIndicesFinder(result, target, remainderVsIndex);
  nums.some(indicesFinder);
  return result;
};

const getIndicesFinder = (result, target, remainderVsIndex) => (ele, index) => {
  const remainder = target - ele;
  if(remainderVsIndex[remainder] !== undefined) {
    result.push(remainderVsIndex[remainder], index);
    return true;
  }
  remainderVsIndex[ele] = index;
  return false;
}

console.log(`\nSolution: ${twoSum([2, 7, 11, 15], 9)}\n`)
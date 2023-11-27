/**
 * @param {number[]} nums
 * @return {number}
 */
const removeDuplicates = function(nums) {
    let filterIndex = 0;
    nums.forEach((ele, index) => {
        if(ele !== nums[index - 1]) {
            nums[filterIndex] = ele;
            filterIndex += 1;
        }
    });
    return filterIndex;
};


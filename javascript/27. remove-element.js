/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
const removeElement = function(nums, filterValue) {
    let replacementIndex = nums.length - 1;
    let runningIndex = 0;
    let tempValueStore = 0;
    while(runningIndex <= replacementIndex) {
        if(nums[runningIndex] === filterValue) {
            tempValueStore = nums[replacementIndex];
            nums[replacementIndex] = nums[runningIndex];
            nums[runningIndex] = tempValueStore;
            replacementIndex--;
        }
        else
            runningIndex++;
    }
    return runningIndex;
};
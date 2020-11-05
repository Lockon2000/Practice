/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    numberOfZeros = 0
    for (let i = nums.length; i >= 0; --i) {
        if (nums[i] === 0) {
            nums.splice(i, 1);
            ++numberOfZeros;
        }
    }

    nums.push(...Array(numberOfZeros).fill(0));
};
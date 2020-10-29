/*
    URL: https://leetcode.com/problems/rotate-array/
*/


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k %= nums.length;
    
    if (k == 0) return;
    
    nums.splice(0, 0, ...nums.slice(-k));
    nums.splice(-k, k);
};
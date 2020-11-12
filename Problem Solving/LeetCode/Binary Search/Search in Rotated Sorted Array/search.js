/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    for (var i = 1; i < nums.length; ++i) {
        if (nums[i] < nums[i-1]) {
            nums = nums.slice(i).concat(nums.slice(0,i));
            break;
        }
    }
    
    if (target < nums[0] || target > nums[nums.length -1]) {
        return -1;
    }
    
    let left = 0;
    let right = nums.length - 1;
    while (left <= right) {
        let middle = Math.floor((right+left)/2);

        if (nums[middle] === target)
            return (middle + i) % nums.length;
        else if (nums[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
};

console.log(search([4,5,6,7,0,1,2], 0));
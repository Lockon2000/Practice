/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let length = nums.length;
    
    let i = 0;
    while (i < length) {
        if (nums[i] == val) {
            nums.splice(i, length-i-1, ...nums.slice(i+1, length));
            --length;
        } else {
            ++i;
        }
    }
    
    return length;
};


a = [3,2,2,3];

removeElement(a, 3);
console.log(a);
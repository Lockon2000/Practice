/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    const offset = nums.length
    
    for (let num of nums) {
        if (num > offset) {
            num -= offset;
        }
        
        if (nums[num-1] <= offset) {
            nums[num-1] += offset;
        }
    }
    
    const result = [];
    for (let i in nums) {
        if (nums[i] <= offset) {
            result.push((+i)+1);
        }
    }
    
    return result;
};

console.log(findDisappearedNumbers([4,3,2,7,8,2,3,1]));
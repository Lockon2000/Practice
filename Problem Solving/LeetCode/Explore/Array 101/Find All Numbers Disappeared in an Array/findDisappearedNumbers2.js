/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    for (let i = 0; i < nums.length; ++i) {
        let num = nums[i];

        if (num < 0) {
            num *= -1;
        }
        
        if (nums[num-1] > 0) {
            nums[num-1] *= -1;
        }
    }
    
    const result = [];
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] > 0) {
            result.push((+i)+1);
        }
    }
    
    return result;
};

console.log(findDisappearedNumbers([4,3,2,7,8,2,3,1]));
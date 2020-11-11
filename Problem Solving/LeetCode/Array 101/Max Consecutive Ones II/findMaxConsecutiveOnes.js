/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
    if (nums.length === 0) {
        return 0;
    }

    let maxCount = 0;
    let prevCount = 0;
    let nextCount = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === 1) {
            ++nextCount;
        } else {
            zeroExits = true;

            maxCount = Math.max(maxCount, prevCount + nextCount);

            prevCount = nextCount + 1;
            nextCount = 0;
        }
    }

    maxCount = Math.max(maxCount, prevCount + nextCount);

    return maxCount;
};

console.log(findMaxConsecutiveOnes([1]));
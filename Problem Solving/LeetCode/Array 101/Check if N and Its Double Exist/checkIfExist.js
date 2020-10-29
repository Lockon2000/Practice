/*
    URL: https://leetcode.com/explore/featured/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/
*/

/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function(arr) {
    const vault = new Set();
    
    for (let val of arr) {
        if (vault.has(2*val)) return true;
        if (val % 2 == 0) {
            if (vault.has(val/2)) return true;
        }
        
        vault.add(val);
    }
    
    return false;
};
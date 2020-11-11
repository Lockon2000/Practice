/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    let ranking = [];
    
    for (item of nums) {
        ranking = Array.from(new Set([...ranking, item])).sort((a,b) => b-a);
        
        if (ranking.length > 3) {
            ranking.length = 3;
        }
    }
    
    if (ranking.length === 3) {
        return ranking[2];
    } else {
        return ranking[0];
    }
};
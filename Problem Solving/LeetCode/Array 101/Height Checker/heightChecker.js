/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    let sortedHeights = heights.slice();
    sortedHeights.sort((a,b) => a - b);
    
    let moved = 0;
    i = heights.length;
    while (i--) {
        if (heights[i] != sortedHeights[i]) ++moved;
    }
    
    return moved;
};
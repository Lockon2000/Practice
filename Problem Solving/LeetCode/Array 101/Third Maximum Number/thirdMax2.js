/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function (nums) {
    let ranking = [-Infinity];

    for (let item of nums) {
        if (ranking.includes(item)) {
            continue;
        }

        for (let i = 0; i < ranking.length; ++i) {
            if (item > ranking[i]) {
                ranking.splice(i, 0, item);
                break;
            }
        }

        if (ranking.length > 4) {
            ranking.length = 4;
        }
    }

    if (ranking.length === 4) {
        return ranking[2];
    } else {
        return ranking[0];
    }
};


console.log(thirdMax([3, 2, 1]));
const LAND = '1';
const WATER = '0';
const VISITED = '2';


/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function (grid) {
    const m = grid.length;
    const n = (grid[0] || []).length;

    if (m === 0 || n === 0) {
        return 0;
    }

    let count = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === LAND) {
                BFS(grid, [i, j]);
                ++count;
            }
        }
    }

    return count;
};

function BFS(grid, start) {
    const queue = [start];
    grid[start[0]][start[1]] = VISITED;

    let headIndex = 0;
    let stepSize = null;
    let point = null;
    while (headIndex < queue.length) {
        stepSize = queue.length - headIndex;
        for (let j = 0; j < stepSize; ++j) {
            point = queue[headIndex++];
            for (let [row, column] of neighbors(grid, point)) {
                if (grid[row][column] !== VISITED) {
                    queue.push([row, column]);
                    grid[row][column] = VISITED;
                }
            }
        }
    }
}

function neighbors(grid, point) {
    const result = [];
    for (let [row, column] of [
        [point[0] - 1, point[1]],
        [point[0] + 1, point[1]],
        [point[0], point[1] - 1],
        [point[0], point[1] + 1]
    ]) {
        if ((0 <= row && row < grid.length) &&
            (0 <= column && column < grid[0].length) &&
            (grid[row][column] !== WATER)) {
            result.push([row, column]);
        }
    }

    return result;
}


const grid = [
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "0"],
]

console.log(numIslands(grid));
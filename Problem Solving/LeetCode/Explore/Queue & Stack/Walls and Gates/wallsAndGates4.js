const Queue = require('@datastructures-js/queue');


/**
 * @param {number[][]} rooms
 * @return {void} Do not return anything, modify rooms in-place instead.
 */
var wallsAndGates = function (rooms) {
    const INF = 2 ** 31 - 1,
          GATE = 0,
          WALL = -1;
    const m = rooms.length,
          n = (rooms[0] || []).length;

    if (m === 0) {
        return;
    }

    const queue = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (rooms[i][j] == GATE) {
                queue.push([i, j]);
            }
        }
    }

    let queueHead = 0;
    let i = 0;
    let stepSize = null;
    let room = null;
    while (queueHead < queue.length) {
        stepSize = queue.length - queueHead;
        for (let l = 0; l < stepSize; ++l) {
            room = queue[queueHead++];
            for (let [row, column] of [
                [room[0] - 1, room[1]],
                [room[0] + 1, room[1]],
                [room[0], room[1] - 1],
                [room[0], room[1] + 1]
            ]) {
                if ((0 <= row && row < m) &&
                (0 <= column && column < n) &&
                rooms[row][column] === INF) {
                    queue.push([row, column]);
                    rooms[row][column] = i + 1;
                }
            }
        }
        ++i;
    }

    return;
};


rooms = [
    [2147483647, -1, 0, 2147483647],
    [2147483647, 2147483647, 2147483647, -1],
    [2147483647, -1, 2147483647, -1],
    [0, -1, 2147483647, 2147483647]
];

wallsAndGates(rooms);

console.log(rooms);
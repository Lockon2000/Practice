const Queue = require('@datastructures-js/queue');


/**
 * @param {number[][]} rooms
 * @return {void} Do not return anything, modify rooms in-place instead.
 */
var wallsAndGates = function (rooms) {
    const INF = 2 ** 31 - 1;

    for (let m = 0; m < rooms.length; ++m) {
        for (let n = 0; n < rooms[0].length; ++n) {
            if (rooms[m][n] == 0) {
                BFS(rooms, [m, n]);
            }
        }
    }

    return;
};

function BFS(rooms, start) {
    const INF = 2 ** 31 - 1;
    const queue = new Queue();
    const visited = new Set();

    queue.enqueue(start);
    visited.add(start);
    let i = 0;
    let room = null;
    let stepSize = null;
    while (!queue.isEmpty()) {
        stepSize = queue.size();
        for (let l = 0; l < stepSize; ++l) {
            room = queue.dequeue();
            rooms[room[0]][room[1]] = Math.min(i, rooms[room[0]][room[1]]);
            for (let neighbour of neighbours(rooms, room)) {
                if (!visited.has(neighbour.toString())) {
                    queue.enqueue(neighbour);
                    visited.add(neighbour.toString());
                }
            }
        }
        ++i;
    }

    return;
}

function neighbours(rooms, room) {
    const INF = 2 ** 31 - 1;
    const result = [];
    for (let [row, column] of [
        [room[0] - 1, room[1]],
        [room[0] + 1, room[1]],
        [room[0], room[1] - 1],
        [room[0], room[1] + 1]
    ]) {
        if ((0 <= row && row < rooms.length) &&
            (0 <= column && column < rooms[0].length)) {
            if (rooms[row][column] !== -1) {
                result.push([row, column]);
            }
        }
    }

    return result;
}

rooms = [
    [2147483647, -1, 0, 2147483647],
    [2147483647, 2147483647, 2147483647, -1],
    [2147483647, -1, 2147483647, -1],
    [0, -1, 2147483647, 2147483647]
];

wallsAndGates(rooms);

console.log(rooms);
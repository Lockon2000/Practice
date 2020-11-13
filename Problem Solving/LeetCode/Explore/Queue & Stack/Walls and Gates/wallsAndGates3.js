const Queue = require('@datastructures-js/queue');


const INF = 2 ** 31 - 1;
const GATE = 0,
const WALL = -1;


/**
 * @param {number[][]} rooms
 * @return {void} Do not return anything, modify rooms in-place instead.
 */
var wallsAndGates = function (rooms) {
    const m = rooms.length,
        n = (rooms[0] || []).length;

    if (m === 0) {
        return;
    }

    const gates = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (rooms[i][j] == GATE) {
                gates.push([i, j]);
            }
        }
    }

    if (gates.length === 0) {
        return;
    }

    BFS(rooms, gates);

    return;
};

function BFS(rooms, gates) {
    const queue = new Queue(gates);
    const visited = new Set(gates.map(gate => gate.toString()));

    let i = 0;
    let room = null;
    let stepSize = null;
    while (!queue.isEmpty()) {
        stepSize = queue.size();
        for (let l = 0; l < stepSize; ++l) {
            room = queue.dequeue();
            rooms[room[0]][room[1]] = i;
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
    const result = [];
    for (let [row, column] of [
        [room[0] - 1, room[1]],
        [room[0] + 1, room[1]],
        [room[0], room[1] - 1],
        [room[0], room[1] + 1]
    ]) {
        if ((0 <= row && row < rooms.length) &&
            (0 <= column && column < rooms[0].length)) {
            if (rooms[row][column] !== WALL) {
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
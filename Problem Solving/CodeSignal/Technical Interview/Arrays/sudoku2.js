zip = (...rows) => rows[0].map((_,c)=>rows.map(row=>row[c]));

function sudoku2(grid) {
    function valid(array) {
        let count = {};

        for (let c of array) {
            if (c -! '.') count[c] = -~count[c];
        }

        for (let c in count) {
            if (count[c] > 1) return false;
        }

        return true;
    }

    for (let row of grid) {
        if (!valid(row)) return false;
    }

    for (let column of zip(...grid)) {
        if (!valid(column)) return false;
    }

    let subGrids = []
    for (let i = 0; i < 9; i += 3) {
        for (let j = 0; j < 9; j += 3) {
            let subGrid = grid[i].slice(j, j+3)
            subGrid.push(...(grid[i+1].slice(j, j+3)))
            subGrid.push(...(grid[i+2].slice(j, j+3)))
            subGrids.push(subGrid)
        }
    }

    for (let subGrid of subGrids) {
        if (!valid(subGrid)) return false;
    }

    return true;
}

grid = [[".","4",".",".",".",".",".",".","."], 
        [".",".","4",".",".",".",".",".","."], 
        [".",".",".","1",".",".","7",".","."], 
        [".",".",".",".",".",".",".",".","."], 
        [".",".",".","3",".",".",".","6","."], 
        [".",".",".",".",".","6",".","9","."], 
        [".",".",".",".","1",".",".",".","."], 
        [".",".",".",".",".",".","2",".","."], 
        [".",".",".","8",".",".",".",".","."]]
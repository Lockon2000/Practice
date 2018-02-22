def sudoku2(grid):
    for row in grid:
        if not valid(row):
            return False

    for column in zip(*grid):
        if not valid(column):
            return False

    subGrid = sum([[sum([grid[j][3*i:3*i+3] for j in range(3)], []) for i in range(3)],
                   [sum([grid[j][3*i:3*i+3] for j in range(3,6)], []) for i in range(3)],
                   [sum([grid[j][3*i:3*i+3] for j in range(6,9)], []) for i in range(3)]], [])

    for sub in subGrid:
        if not valid(sub):
            return False

    return True


def valid(row):
    count = [0]*9

    for n in row:
        if n != '.':
            count[int(n)-1] += 1

    for n in count:
        if n > 1:
            return False

    return True


grid = [[".","4",".",".",".",".",".",".","."], 
        [".",".","4",".",".",".",".",".","."], 
        [".",".",".","1",".",".","7",".","."], 
        [".",".",".",".",".",".",".",".","."], 
        [".",".",".","3",".",".",".","6","."], 
        [".",".",".",".",".","6",".","9","."], 
        [".",".",".",".","1",".",".",".","."], 
        [".",".",".",".",".",".","2",".","."], 
        [".",".",".","8",".",".",".",".","."]]


print(sudoku2(grid))
def sudoku2_1(grid):
    def valid(array):
        count = [0]*9

        for n in array:
            if n != '.':
                count[int(n)-1] += 1

        for n in count:
            if n > 1:
                return False

        return True

    for row in grid:
        if not valid(row):
            return False

    for column in zip(*grid):
        if not valid(column):
            return False

    subGrids = sum([[sum([grid[j][3*i:3*i+3] for j in range(0,3)], []) for i in range(3)],
                    [sum([grid[j][3*i:3*i+3] for j in range(3,6)], []) for i in range(3)],
                    [sum([grid[j][3*i:3*i+3] for j in range(6,9)], []) for i in range(3)]], [])

    for subGrid in subGrids:
        if not valid(subGrid):
            return False

    return True

def sudoku2_2(grid):
    def valid(array):
        count = {}

        for c in array:
            if c != '.':
                count[c] = count.get(c, 0) + 1

        for c in count:
            if count[c] > 1:
                return False

        return True

    for row in grid:
        if not valid(row):
            return False

    for column in zip(*grid):
        if not valid(column):
            return False

    subGrids = sum([[sum([grid[j][3*i:3*i+3] for j in range(0,3)], []) for i in range(3)],
                    [sum([grid[j][3*i:3*i+3] for j in range(3,6)], []) for i in range(3)],
                    [sum([grid[j][3*i:3*i+3] for j in range(6,9)], []) for i in range(3)]], [])

    for subGrid in subGrids:
        if not valid(subGrid):
            return False

    return True

def sudoku2_3(grid):
    def valid(array):
        array = [x for x in array if x != '.']
        return len(set(array)) == len(array)

    for row in grid:
        if not valid(row):
            return False

    for column in zip(*grid):
        if not valid(column):
            return False

    subGrids = sum([[sum([grid[j][3*i:3*i+3] for j in range(0,3)], []) for i in range(3)],
                    [sum([grid[j][3*i:3*i+3] for j in range(3,6)], []) for i in range(3)],
                    [sum([grid[j][3*i:3*i+3] for j in range(6,9)], []) for i in range(3)]], [])

    for subGrid in subGrids:
        if not valid(subGrid):
            return False

    return True



import timeit
grid = [[".","4",".",".",".",".",".",".","."], 
        [".",".","4",".",".",".",".",".","."], 
        [".",".",".","1",".",".","7",".","."], 
        [".",".",".",".",".",".",".",".","."], 
        [".",".",".","3",".",".",".","6","."], 
        [".",".",".",".",".","6",".","9","."], 
        [".",".",".",".","1",".",".",".","."], 
        [".",".",".",".",".",".","2",".","."], 
        [".",".",".","8",".",".",".",".","."]]
setup = ("from __main__ import sudoku2_1, sudoku2_2, sudoku2_3, grid")

print(timeit.timeit("sudoku2_1(grid)", setup=setup, number=10000))
print(timeit.timeit("sudoku2_2(grid)", setup=setup, number=10000))
print(timeit.timeit("sudoku2_3(grid)", setup=setup, number=10000))

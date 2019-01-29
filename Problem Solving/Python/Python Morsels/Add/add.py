import itertools

def add(*matrices):
    heighte = len(matrices[0])
    length = len(matrices[0][0])
    for x in matrices:
        if len(x) != heighte:
            raise ValueError("Given matrices are not the same size.")
        for y in x:
            if len(y) != length:
                raise ValueError("Given matrices are not the same size.")
    lmatrices = []
    for m in matrices:
        lmatrices.append(itertools.chain(*m))
    zmatrices = zip(*lmatrices)
    fmatrix = list(map(sum, zmatrices))
    return [fmatrix[x:x+length] for x in range(0, length*heighte, length)]
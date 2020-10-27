def isCryptSolution(crypt, solution):
    nCrypt = "".join(crypt)

    for s,i in solution:
        nCrypt = nCrypt.replace(s,i)

    lenght1 = len(crypt[0])
    lenght2 = len(crypt[1])
    lenght3 = len(crypt[2])

    crypt = [nCrypt[:lenght1],
             nCrypt[lenght1:lenght1+lenght2],
             nCrypt[lenght1+lenght2:]]

    if (lenght1 != 1 and crypt[0][0] == '0') or \
       (lenght2 != 1 and crypt[1][0] == '0') or \
       (lenght3 != 1 and crypt[2][0] == '0'):
        return False

    if int(crypt[0]) + int(crypt[1]) == int(crypt[2]):
        return True
    else:
        return False

def isCryptSolution2(crypt, solution):
    table = {ord(c): i for c,i in solution}
    *translatedCrypt, = map(lambda x: x.translate(table), crypt)

    return (not any(s.startswith('0') and len(s) != 1 for s in translatedCrypt) and
            int(translatedCrypt[0]) + int(translatedCrypt[1]) == int(translatedCrypt[2]))


crypt = ["AA", "B", "AA"]
solution= [["A","1"], 
           ["B","0"]]

print(isCryptSolution2(crypt, solution))
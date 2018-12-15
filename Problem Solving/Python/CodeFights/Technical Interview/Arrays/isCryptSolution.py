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



crypt= ["AA", 
 "BB", 
 "AA"]
solution= [["A","1"], 
 ["B","0"]]


print(isCryptSolution(crypt, solution))
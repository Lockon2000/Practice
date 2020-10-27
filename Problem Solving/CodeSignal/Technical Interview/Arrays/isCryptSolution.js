function isCryptSolution(crypt, solution) {
    table = solution.reduce((s, v) => { return {...s, [v[0]]: v[1]} }, {})
    translatedCrypt = crypt.map((s) => (Array.from(s).map((c) => table[c])).join(""))

    return !(translatedCrypt.some((s) => s[0] == "0" && s != "0")) &&
           Number(translatedCrypt[0]) + Number(translatedCrypt[1]) == Number(translatedCrypt[2])
}


crypt = ["TEN", "TWO", "ONE"]

solution = [["O","1"], 
 ["T","0"], 
 ["W","9"], 
 ["E","5"], 
 ["N","4"]]
function firstNotRepeatingCharacter(s) {
    const Store = Object()
    const SmallACodePoint = 97;

    for (let i = 0; i < 26; ++i) {
        Store[String.fromCharCode(SmallACodePoint+i)] = {
            position: null,
            repetition: 0,
        }
    }
    
    for (let index in s) {
        Store[s[index]].repetition += 1;
        
        if (Store[s[index]].position === null) {
            Store[s[index]].position = Number(index) + 1;
        }
    }
    
    result = '_';
    minPos = s.length+1;
    
    for (let c in Store) {
        if (Store[c].repetition === 1) {
            if (Store[c].position < minPos) {
                result = c;
                minPos = Store[c].position;
            }
        }
    }

    return result;
}

// Much faster and more elegent
firstNotRepeatingCharacter = s => {
    r = {}
    for (e of s)
        r[e] = r[e] ? r[e]+1 : 1  // or r[e] = -~r[e]
    for (e in r)
        if (r[e] == 1)
            return e
    return '_'
}

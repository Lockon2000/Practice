import timeit

# Wrong answer
def firstNotRepeatingCharacter1(s):
    for i in range(len(s)):
        if s[i+1:].find(s[i]) == -1:
            return s[i]

    return '_'

# Wrong answer and slower than the first one
def firstNotRepeatingCharacter2(s):
    for c in s:
        if s.find(c, s.find(c)+1) == -1:
            return c

    return '_'

# Right answer and faster than the last answer but could be done in much less code
def firstNotRepeatingCharacter3(s):
    length = len(s)
    alphabet = [(0,length,i) for i in range(26)]
    alphabet.append((0,length,26))

    for i in range(length):
        place = ord(s[i]) - 97
        if alphabet[place][0] == 0:
            alphabet[place] = (1, i, alphabet[place][2])
        elif alphabet[place][0] == 1:
            alphabet[place] = (2, alphabet[place][1], alphabet[place][2])

    smallest = 26
    for i in range(1,26):
        if alphabet[i][0] == 1:
            if alphabet[i][1] < alphabet[smallest][1]:
                smallest = alphabet[i][2]

    if alphabet[smallest][0] == 1:
        return chr(alphabet[smallest][2]+97)
    else:
        return '_'

# Right answer and elegant but slower. Also it could be argued that it traverses the sring more the once
def firstNotRepeatingCharacter4(s):
    for c in s:
        if s.index(c) == s.rindex(c):
            return c
    return '_'

# s = "abacabad"

# print(firstNotRepeatingCharacter4(s))



s = "ajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidfajfsakvnasndhzyurpwiaffjaskduwerpoisadjkfljwerlkuasidf"
st = "from __main__ import firstNotRepeatingCharacter1, firstNotRepeatingCharacter2, firstNotRepeatingCharacter3, firstNotRepeatingCharacter4, s"

print(timeit.timeit("firstNotRepeatingCharacter1(s)", setup=st, number=1000))
print(timeit.timeit("firstNotRepeatingCharacter2(s)", setup=st, number=1000))
print(timeit.timeit("firstNotRepeatingCharacter3(s)", setup=st, number=1000))
print(timeit.timeit("firstNotRepeatingCharacter4(s)", setup=st, number=1000))
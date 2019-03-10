from collections import Counter

def is_anagram(firstString, secondString):
    firstString, secondString = firstString.lower(), secondString.lower()
    firstString, secondString = firstString.replace(" ", ""), secondString.replace(" ", "")
    firstLetters = [char for char in firstString if char.isalpha()]
    secondLetters = [char for char in secondString if char.isalpha()]

    if Counter(firstLetters) == Counter(secondLetters):
        return True
    else:
        return False
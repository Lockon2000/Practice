import re

def count_words(string):
    mapping = {}

    splittedString = re.findall(r"\b\w[\w'-]*\w\b|\b\w\b", string.lower())

    for s in splittedString:
        if s not in mapping:
            mapping[s] = 0
        mapping[s] += 1

    return mapping

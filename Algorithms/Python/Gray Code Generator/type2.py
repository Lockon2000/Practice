# This program generates Gray Code, i. e. subsets of {1..n}  with
# "minimal change" between one another. Here we generate the subsets
# by generating the corresponding increasing sequences in a certain order.

# Type two is my own designation to differentiate the different gray codes.

# This is a solution for a question in chapter 8 in the book "Discrete
# Math for Computer Science".

# Invoke with: .\type2.py <value-for-n>

from sys import argv
from math import log10, floor

def generateGrayCode(n):
    def processSequence(s):
        processSequence.counter = getattr(processSequence, "counter", 0) + 1 
        widthOfMaxCount = floor(log10(2**n)) + 1
        print(f"{processSequence.counter:{widthOfMaxCount}}. [", end="")
        print(*s, sep=",", end="]\n")

    s = [1]
    processSequence(s[:len(s)])

    while s[0] < n:
        if s[len(s)-1] == n:
            s.pop()
        else:
            s.append(n)
        processSequence(s[:len(s)])

        if s[len(s)-2] == s[len(s)-1] - 1:
            s[len(s)-2] = s[len(s)-1]
            s.pop()
        else:
            s[len(s)-1] -= 1
            s.append(s[len(s)-1]+1)
        processSequence(s[:len(s)])

if __name__ == "__main__":
    generateGrayCode(int(argv[1]))

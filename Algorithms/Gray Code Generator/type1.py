# This program generates Gray Code, i. e. subsets of {1..n}  with
# "minimal change" between one another. Here we generate the subsets
# by generating the characteristic bit vectors in a certain order.

# Type one is my own designation to differentiate the different gray codes.

# This is a solution for a question in chapter 8 in the book "Discrete
# Math for Computer Science".

# Invoke with: .\type1.py <value-for-n>

from sys import argv
from math import log10, floor

def generateGrayCode(n):
    def processSequence(s):
        processSequence.counter = getattr(processSequence, "counter", 0) + 1 
        widthOfMaxCount = floor(log10(2**n)) + 1
        print(f"{processSequence.counter:{widthOfMaxCount}}. [", end="")
        print(*(s[::-1]), sep=",", end="] ")
        X = ["x"+str(i+1)+"," if s[i] else "   " for i in range(n-1,0,-1)] + \
            ["x1" if s[0] else "  "]
        print("{", end="")
        print(*X, sep="", end="}\n")

    def rotate(start, end):
        for i in range(start,end+1):
            toggle(i)
            processSequence(s)
            rotate(start, i-1)

    def toggle(i):
        s[i] = 1 if s[i] == 0 else 0

    s = [0 for _ in range(n)]
    processSequence(s)
    rotate(0,n-1)

if __name__ == "__main__":
    generateGrayCode(int(argv[1]))

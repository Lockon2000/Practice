"""
    URL: https://leetcode.com/explore/featured/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
"""


class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if (n := len(A)) < 3:
            return False

        if A[0] > A[1]:
            return False

        reachedSummit = False

        for i in range(n - 1):
            if A[i] < A[i + 1]:
                if reachedSummit:
                    return False
            elif A[i] > A[i + 1]:
                reachedSummit = True
            else:  # A[i] == A[i+1]
                return False

        if not reachedSummit:
            return False
        else:
            return True

'''
    URL: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
'''


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        vault = set()
        
        for val in nums:
            if val in vault:
                return True
            else:
                vault.add(val)
        
        return False
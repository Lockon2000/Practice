class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = 1
        u = 0
        for item in nums:
            if item != nums[u]:
                u += 1
                nums[u] = item
                length += 1
            
        return length
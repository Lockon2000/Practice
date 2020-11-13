class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = len(nums)
        i = 0
        while i < length-1:
            if nums[i+1] == nums[i]:
                nums[i+1:] = nums[i+2:]
                length -= 1
            else:
                i += 1
        
        return length

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        i = len(nums1)-1
        while m and n:
            if nums2[n-1] > nums1[m-1]:
                nums1[i] = nums2[n-1]
                n -= 1
                i -= 1
            else:
                nums1[i] = nums1[m-1]
                m -= 1
                i -= 1
        
        if n > 0:
            nums1[:i+1] = nums2[:n]
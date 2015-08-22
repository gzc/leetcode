class Solution(object):
    def nextPermutation(self, nums):
        """
            :type nums: List[int]
            :rtype: void Do not return anything, modify nums in-place instead.
            """
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
        left = i+1
        right = len(nums)-1;
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
        
        if i == -1:
            return
        
        j = 0
        v = 100000000
        for k in range(i+1, len(nums)):
            if nums[k] > nums[i] and nums[k] < v:
                j = k
                v = nums[k]
        nums[i], nums[j] = nums[j], nums[i]
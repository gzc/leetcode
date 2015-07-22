class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if not nums:
            return 0
        if(len(nums) == 1):
            return nums[0]
        
        p = [0]*len(nums)
        p[0] = nums[0]
        p[1] = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            p[i] = max(p[i-2] + nums[i], p[i-1])
        
        return p[-1]
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        pre1 = cur1 = 0
        for i in range(len(nums)-1):
            temp = pre1
            pre1 = cur1
            cur1 = max(temp+nums[i], pre1)
        
        pre2 = cur2 = 0
        for i in range(1, len(nums)):
            temp = pre2
            pre2 = cur2
            cur2 = max(temp+nums[i], pre2)
        
        return max(cur1, cur2)
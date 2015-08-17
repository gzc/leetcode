class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        l = len(nums)
        res = 0
        for i in range(l):
            if i <= res:
                res = max(res, i+nums[i]);
        if res >= l-1:
            return True
        return False
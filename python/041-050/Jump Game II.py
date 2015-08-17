class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        step = 0
        nextstep = 0
        count = 0
        
        for i in range(len(nums)):
            if i+nums[i] > nextstep:
                nextstep = i + nums[i]
            if i == step and i != len(nums)-1:
                count += 1
                step = nextstep
        
        return count
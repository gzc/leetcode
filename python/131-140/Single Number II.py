class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        tmp = set(nums)
        v = sum(tmp)*3 -sum(nums)
        return v/2


s = Solution()
items = [2,2,3,2]
print s.singleNumber(items)
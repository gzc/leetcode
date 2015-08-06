class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        ls = len(nums)
        result = [0]*ls
        result[0] = 1
        tmp = 1
        
        for i in range(1,ls):
            result[i] = result[i-1]*nums[i-1]
        for i in range(ls-2, -1, -1):
            tmp = tmp * nums[i+1]
            result[i] = result[i]*tmp
        
        return result


items = [0,1]
s = Solution()
print s.productExceptSelf(items)
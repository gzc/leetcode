class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer[]}
    def maxSlidingWindow(self, nums, k):
        myqueue,res = [],[]
        for i in range(len(nums)):
            if len(myqueue) > 0 and myqueue[0] == i - k:
                del myqueue[0]
            while len(myqueue) > 0 and nums[myqueue[-1]] < nums[i]:
                del myqueue[-1]
            myqueue.append(i)
            if i >= k - 1:
                res.append(nums[myqueue[0]])

    return res
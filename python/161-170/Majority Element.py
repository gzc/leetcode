class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        stack = []
        for e in nums:
            if len(stack) == 0:
                stack.append(e)
            else:
                if stack[-1] == e:
                    stack.append(e)
                else:
                    del stack[-1]
        return stack[0]

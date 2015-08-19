class Solution:
    # @param {integer[]} height
    # @return {integer}
    def largestRectangleArea(self, height):
        res = 0
        height.append(0)
        mystack = []
        
        for i in range(len(height)):
            if len(mystack) == 0 or height[i] >= height[mystack[-1]]:
                mystack.append(i)
            else:
                while len(mystack) > 0 and height[i] < height[mystack[-1]]:
                    h = height[mystack[-1]]
                    del mystack[-1]
                    width = i if len(mystack) == 0 else i - 1 - mystack[-1]
                    res = max(res, width*h)
                mystack.append(i)
        return res
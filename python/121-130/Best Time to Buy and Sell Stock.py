class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        res = 0
        minimum = 2**31-1
        for e in prices:
            res = max(res, e - minimum)
            minimum = min(minimum, e) 
        return res

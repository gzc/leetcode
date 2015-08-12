#!/usr/bin/env python
# coding=utf-8

class Solution:
    # @param {integer} k
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, k, prices):
        l = len(prices)
        if l < 2:
            return 0
        if k >= l/2:
            res = 0
            for i in range(l-1):
                if prices[i+1] > prices[i]:
                    res = res + prices[i+1] - prices[i]
            return res
    
        p = [[0]*(l+1) for _ in range(k+1)]
        for i in range(1,k+1):
            temp = -prices[0]
            for j in range(1,l+1):
                p[i][j] = max(p[i][j-1], temp+prices[j-1])
                temp = max(temp, p[i-1][j-1]-prices[j-1])
        return p[k][l]
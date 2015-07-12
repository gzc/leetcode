#!/usr/bin/env python
# coding=utf-8

class Solution:
    # @param {string} s
    # @return {integer}
    def numDecodings(self, s):
        if not s:
            return 0
        
        dp = [0]*(len(s)+1)
        dp[0] = 1
        for i in xrange(len(s)):
            if self.isValid(s[i]):
                dp[i+1] = dp[i]
            if i>0 and self.isValid(s[i-1:i+1]):
                dp[i+1] += dp[i-1]
        return dp[-1]
    
    def isValid(self,s):
        if len(s) == 1 and 0<int(s) <10:
            return True
        if len(s) == 2 and 10 <= int(s) <= 26:
            return True
#!/usr/bin/env python
# coding=utf-8

class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum(self, candidates, target):
        candidates.sort()
        result = []
        tmp = []
        self.help(tmp, candidates, 0, target, result)
        return result
    
    def help(self, now, candidates, index, target, result):
        for i in range(index, len(candidates)):
            if candidates[i] < target:
                now.append(candidates[i]);
                self.help(now, candidates, i, target-candidates[i], result)
                del now[-1]
            elif candidates[i] == target:
                now.append(candidates[i])
                temp = now[:]
                result.append(temp)
                del now[-1]
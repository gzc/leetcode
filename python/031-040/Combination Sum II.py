class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum2(self, candidates, target):
        candidates.sort()
        result = []
        tmp = []
        self.help(tmp, candidates, 0, target, result)
        return result
    
    def help(self, now, candidates, index, target, result):
        i = index
        while i < len(candidates):
            if candidates[i] < target:
                now.append(candidates[i]);
                self.help(now, candidates, i+1, target-candidates[i], result)
                del now[-1]
                while i < len(candidates)-1 and candidates[i] == candidates[i+1]:
                    i += 1
            elif candidates[i] == target:
                temp = now[:]
                temp.append(candidates[i])
                result.append(temp)
                return
            i += 1
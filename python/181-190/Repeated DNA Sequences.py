class Solution:
    # @param {string} s
    # @return {string[]}
    def findRepeatedDnaSequences(self, s):
        result = []
        t = i = 0
        ss = len(s)
        if ss < 10:
            return result
        dic = {}
        
        while i < 9:
            t = t << 3 | ord(s[i]) & 7
            i = i + 1
        
        while i < ss:
            t = t << 3 & 0x3FFFFFFF | ord(s[i]) & 7
            i = i + 1
            
            if t in dic:
                dic[t] = dic[t]+1
            else:
                dic[t] = 1
            if dic[t] == 2:
                result.append(s[i-10:i]);

        return result

s = Solution()
st = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
print s.findRepeatedDnaSequences(st)
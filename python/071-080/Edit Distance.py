class Solution:
    # @param {string} word1
    # @param {string} word2
    # @return {integer}
    def minDistance(self, word1, word2):
        n,m = len(word1), len(word2)
        p = [[0]*(m+1) for _ in range(n+1)]
        
        for i in range(1, n+1):
            p[i][0] = i
        for i in range(1, m+1):
            p[0][i] = i
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                f = 1 if word1[i-1] != word2[j-1] else 0
                p[i][j] = min(p[i-1][j]+1, p[i][j-1]+1, p[i-1][j-1]+f);
        
        return p[n][m]
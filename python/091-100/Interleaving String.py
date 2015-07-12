class Solution:
    # @param {string} s1
    # @param {string} s2
    # @param {string} s3
    # @return {boolean}
    def isInterleave(self, s1, s2, s3):
        m = len(s1)
        n = len(s2)
        if m+n != len(s3):
            return False
        
        table = [([False] * (m+1)) for i in range(n+1)]
        table[0][0] = True
        for i in range (1, m+1):
            if s3[i-1] == s1[i-1] and table[0][i-1] == True:
                table[0][i] = True
        for i in range (1, n+1):
            if s3[i-1] == s2[i-1] and table[i-1][0] == True:
                table[i][0] = True
    
        for i in range (1, n+1):
            for j in range(1, m+1):
                if s3[i+j-1] == s2[i-1] and table[i-1][j] == True:
                    table[i][j] = True
                if s3[i+j-1] == s1[j-1] and table[i][j-1] == True:
                    table[i][j] = True

                        return table[n][m]
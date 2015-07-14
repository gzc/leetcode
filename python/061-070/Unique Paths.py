class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def uniquePaths(self, m, n):
        table = [([0] * (n+1)) for i in range(m+1)]
        table[1][1] = 1
        for i in range(1,m+1):
            for j in range(1,n+1):
                if i == 1 and j == 1:
                    continue
                table[i][j] = table[i-1][j] + table[i][j-1]
        return table[m][n]
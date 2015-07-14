class Solution:
    # @param {integer[][]} obstacleGrid
    # @return {integer}
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1:
            return 0
        table = [([0] * (n+1)) for i in range(m+1)]
        table[1][1] = 1
        for i in range(1,m+1):
            for j in range(1,n+1):
                if i == 1 and j == 1:
                    continue
                if obstacleGrid[i-1][j-1] == 1:
                    table[i][j] = 0
                else:
                    table[i][j] = table[i-1][j] + table[i][j-1]
        return table[m][n]
class Solution:
    # @param {integer[][]} grid
    # @return {integer}
    def minPathSum(self, grid):
        n = len(grid);
        m = len(grid[0]);
        p = [([0] * m) for i in range(n)]
        p[0][0] = grid[0][0];
        
        for k in range (1, n):
            p[k][0] = p[k-1][0]+grid[k][0];
        for k in range (1, m):
            p[0][k] = p[0][k-1]+grid[0][k];
        
        for i in range (1, n):
            for j in range (1, m):
                    p[i][j] = min(p[i-1][j], p[i][j-1]) + grid[i][j];
        
        return p[n-1][m-1];

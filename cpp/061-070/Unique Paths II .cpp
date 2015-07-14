class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> p(m+1,vector<int>(n+1,0));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        p[1][1] = 1;
        
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(i == 1 && j == 1) continue;
                if(obstacleGrid[i-1][j-1] == 1)
                    p[i][j] = 0;
                else
                    p[i][j] = p[i-1][j] + p[i][j-1];
            }
        }
        return p[m][n];
    }
    
};
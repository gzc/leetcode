class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> p(m,vector<int>(n,0));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        p[0][0] = 1;
        for(int i = 1;i < m;i++)
        {
            if(obstacleGrid[i][0] == 1)
                p[i][0] = 0;
            else
                p[i][0] = p[i-1][0];
        }
        for(int i = 1;i < n;i++)
        {
            if(obstacleGrid[0][i] == 1)
                p[0][i] = 0;
            else
                p[0][i] = p[0][i-1];
        }
        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                    p[i][j] = 0;
                else
                    p[i][j] = p[i-1][j] + p[i][j-1];
            }
        }
        return p[m-1][n-1];
    }
    
};
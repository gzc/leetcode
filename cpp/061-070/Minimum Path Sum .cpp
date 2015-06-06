public:
int minPathSum(vector<vector<int> > &grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    int p[n][m];
    p[0][0] = grid[0][0];
    
    
    for(int k = 1;k < n;k++)
        p[k][0] = p[k-1][0]+grid[k][0];
    for(int k = 1;k < m;k++)
        p[0][k] = p[0][k-1]+grid[0][k];
    
    for(int i = 1;i < n;i++)
        for(int j = 1;j < m;j++)
            p[i][j] = min(p[i-1][j], p[i][j-1]) + grid[i][j];
    
    return p[n-1][m-1];
}
};
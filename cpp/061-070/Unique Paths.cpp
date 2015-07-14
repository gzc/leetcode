class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> p(m+1,vector<int>(n+1,0));
        p[1][1] = 1;
        
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++)
                p[i][j] = p[i-1][j] + p[i][j-1];
        return p[m][n];
    }
};

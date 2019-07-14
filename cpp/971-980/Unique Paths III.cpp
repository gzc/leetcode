class Solution {
    
    int dfs(vector<vector<int>>& grid, int i, int j, int w, int h, int n) {
        if (i < 0 || i >= w || j < 0 || j >= h) return 0;
        if (grid[i][j] == -1) return 0;
        if (grid[i][j] == 999) return 0;
        if (grid[i][j] == 2) {
            if (n == -1) return 1;
            else return 0;
        }
        
        grid[i][j] = 999;
        int ans = 0;
        ans += dfs(grid, i-1, j, w, h, n-1);
        ans += dfs(grid, i+1, j, w, h, n-1);
        ans += dfs(grid, i, j-1, w, h, n-1);
        ans += dfs(grid, i, j+1, w, h, n-1);
        grid[i][j] = 0;
        
        return ans;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int w = grid.size();
        int h = grid.front().size();
        
        int n = 0;
        int ii, jj;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (grid[i][j] == 0) {
                    n++;
                }
                if (grid[i][j] == 1) {
                    ii = i;
                    jj = j;
                }
            }
        }
        
        return dfs(grid, ii, jj, w, h, n);
    }
};

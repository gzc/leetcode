class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid.back().size();
        if(cols == 0) return 0;
        vector<vector<int>> l2r(rows, vector<int>(cols, 0));
        vector<vector<int>> r2l(rows, vector<int>(cols, 0));
        vector<vector<int>> u2d(rows, vector<int>(cols, 0));
        vector<vector<int>> d2u(rows, vector<int>(cols, 0));
        
        for(int i = 0;i < rows;i++) {
            int cnt(0);
            for(int j = 0;j < cols;j++) {
                if(grid[i][j] == 'W') {
                    cnt = 0;
                } else if(grid[i][j] == 'E') {
                    cnt++;
                } else {
                    l2r[i][j] = cnt;
                }
            }
        }
        
        for(int i = 0;i < rows;i++) {
            int cnt(0);
            for(int j = cols-1;j >= 0;j--) {
                if(grid[i][j] == 'W') {
                    cnt = 0;
                } else if(grid[i][j] == 'E') {
                    cnt++;
                } else {
                    r2l[i][j] = cnt;
                }
            }
        }
        
        for(int i = 0;i < cols;i++) {
            int cnt(0);
            for(int j = 0;j < rows;j++) {
                if(grid[j][i] == 'W') {
                    cnt = 0;
                } else if(grid[j][i] == 'E') {
                    cnt++;
                } else {
                    u2d[j][i] = cnt;
                }
            }
        }
        
        for(int i = 0;i < cols;i++) {
            int cnt(0);
            for(int j = rows-1;j >= 0;j--) {
                if(grid[j][i] == 'W') {
                    cnt = 0;
                } else if(grid[j][i] == 'E') {
                    cnt++;
                } else {
                    d2u[j][i] = cnt;
                }
            }
        }
        
        int res(0);
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                res = max(res, l2r[i][j]+r2l[i][j]+u2d[i][j]+d2u[i][j]);
            }
        }
        
        return res;
    }
};

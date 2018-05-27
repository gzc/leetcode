class Solution {
    
    bool validate(int i, int j, vector<vector<int>>& grid) {
        if (i + 2 >= grid.size() || j + 2 >= grid.front().size()) return false;
        int sum1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int sum2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int sum3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
        int sum4 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int sum5 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int sum6 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
        int sum7 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int sum8 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
        set<int> myset{grid[i][j], grid[i][j+1], grid[i][j+2], grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2], grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]};
        if (myset.size() != 9) return false;
        if (*myset.begin() != 1) return false;
        if (*myset.rbegin() != 9) return false;
        if (sum1 != sum2) return false;
        if (sum1 != sum3) return false;
        if (sum1 != sum4) return false;
        if (sum1 != sum5) return false;
        if (sum1 != sum6) return false;
        if (sum1 != sum7) return false;
        if (sum1 != sum8) return false;
        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if (grid.empty() || grid.front().empty()) return 0;
        int m = grid.size();
        int n = grid.front().size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (validate(i, j, grid)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

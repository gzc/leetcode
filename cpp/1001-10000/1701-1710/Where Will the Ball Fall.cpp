class Solution {
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        
        int m = grid.size();
        int n = grid.front().size();
        
        for (int i = 0; i < n; i++) {
            int row = 0;
            int col = i;
            
            while(row < m) {
                if (grid[row][col] == 1) {
                    if (col == n-1 || grid[row][col+1] == -1) break;
                    col++;
                } else {
                    if (col == 0 || grid[row][col-1] == 1) break;
                    col--;
                }
                row++;
            }
            
            ans.push_back(row == m ? col : -1);
        }
        
        return ans;
    }
};

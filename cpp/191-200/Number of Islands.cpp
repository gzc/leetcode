class Solution {
    
    bool valid(int i, int j) {
        if(i >= 0 && j >= 0 && i < M && j < N) return true;
        return false;
    }
    
    void mark(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        if (valid(i+1,j)) mark(grid, i+1, j);
        if (valid(i-1,j)) mark(grid, i-1, j);
        if (valid(i,j+1)) mark(grid, i, j+1);
        if (valid(i,j-1)) mark(grid, i, j-1);
    }
    
    size_t M;
    size_t N;
public:
    
    int numIslands(vector<vector<char>> &grid) {
        int result(0);
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        M = grid.size();
        N = grid[0].size();
        
        for (int i = 0;i < M;i++) {
            for (int j = 0;j < N;j++) {
                if(grid[i][j] == '1') {
                    result++;
                    mark(grid, i, j);
                }
            }
        }
        return result;
    }
};

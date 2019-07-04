class Solution {
    
    int old_color;
    int new_color;
    int row;
    int col;
    pair<int, int> tmp[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        
        bool has_non_connected_cells = false;
        for (int k = 0; k < 4; k++) {
            int new_i = i + tmp[k].first;
            int new_j = j + tmp[k].second;
            if (new_i < 0 || new_j < 0 || new_i >= row || new_j >= col || visited[new_i][new_j]) continue;
            if (grid[new_i][new_j] == old_color) {
                dfs(grid, new_i, new_j, visited);
            } else {
                has_non_connected_cells = true;
            }
        }
        
        has_non_connected_cells |= (i == 0 || j == 0 || i == row-1 || j == col-1);
        
        if (has_non_connected_cells) {
            grid[i][j] = new_color;
        }
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        old_color = grid[r0][c0];
        new_color = color;
        row = grid.size();
        col = grid.front().size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        dfs(grid, r0, c0, visited);
        return grid;
    }
};

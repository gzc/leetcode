class Solution {
    
    int dfsvisit(int i, int j, vector<vector<bool>> &visited, vector<vector<int>>& lens, vector<vector<int>>& matrix) {
        
        pair<int, int> pos[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        for (int k = 0;k < 4;k++) {
            int ni = i + pos[k].first;
            int nj = j + pos[k].second;
            if(ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size()) continue;
            if(matrix[i][j] >= matrix[ni][nj]) continue;
            if(visited[ni][nj]) lens[i][j] = max(lens[i][j], lens[ni][nj]+1);
            else lens[i][j] = max(lens[i][j], 1 + dfsvisit(ni, nj, visited, lens, matrix));
        }
        
        visited[i][j] = true;
        return lens[i][j];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        vector<vector<int>> lens(m,vector<int>(n, 1));
        
        int _max(0);
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (!visited[i][j]) {
                    _max = max(_max, dfsvisit(i, j, visited, lens, matrix));
                }
            }
        }
        
        return _max;
    }
};

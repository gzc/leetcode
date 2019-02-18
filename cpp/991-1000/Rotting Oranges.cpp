class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS
        queue<pair<int, int>> rot;
        int previous_fresh = -1;
        int fresh = 0;
        int h = grid.size();
        int w = grid.front().size();
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    rot.push({i, j});
                }
            }
        }
        
        int day = 0;
        while (!rot.empty() && fresh > 0) {
            previous_fresh = fresh;
            int n = rot.size();
            
            for (int i = 0; i < n; i++) {
                auto e = rot.front();
                rot.pop();
                
                pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                
                for (int j = 0; j < 4; j++) {
                    int newi = e.first + directions[j].first;
                    int newj = e.second + directions[j].second;
                    if (newi < 0 || newj < 0 || newi >= h || newj >= w) continue;
                    
                    if (grid[newi][newj] == 1) {
                        fresh--;
                        rot.push({newi, newj});
                        grid[newi][newj] = 2;
                    }
                }
            }
            
            day++;
        }
        
        return fresh == 0 ? day : -1;
    }
};

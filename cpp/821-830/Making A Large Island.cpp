class Solution {
    
    int dfs(pair<int, int> pos, const pair<int, int>& root, const vector<vector<int>>& grid, map<pair<int, int>, pair<int, int>>& roots) {
        roots[pos] = root;
        
        int m = grid.size();
        int n = grid.front().size();
        
        pair<int, int> xys[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int ni = pos.first + xys[i].first;
            int nj = pos.second + xys[i].second;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (grid[ni][nj] == 0) continue;
            if (roots.find({ni, nj}) != roots.end()) continue;
            area += dfs(make_pair(ni, nj), root, grid, roots);
        }
        return area;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        map<pair<int, int>, int> areas; // coordinate -> area
        map<pair<int, int>, pair<int, int>> roots;
        
        int m = grid.size();
        int n = grid.front().size();
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                pair<int, int> cur = make_pair(i, j);
                if (roots.find(cur) == roots.end()) {
                    int area = dfs(cur, cur, grid, roots);
                    areas[cur] = area;
                    ans = max(ans, area);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<pair<int, int>> used;
                    pair<int, int> xys[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                    int area = 1;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + xys[k].first;
                        int nj = j + xys[k].second;
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        if (grid[ni][nj] == 0) continue;
                        pair<int, int> curRoot = roots[make_pair(ni, nj)];
                        if (used.count(curRoot) == 0) {
                            used.insert(curRoot);
                            area += areas[curRoot];
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        
        return ans;
    }
};

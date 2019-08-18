class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> myqueue;
        set<pair<int, int>> visited;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (grid[i][j] == 1) {
                    myqueue.push({i, j});
                    visited.insert({i, j});
                }
            }
        }
        
        pair<int, int> tmp[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int dis = 1;
        int res = -1;
        while (!myqueue.empty()) {
            int sizes = myqueue.size();
            for (int i = 0; i < sizes; i++) {
                pair<int, int> ele = myqueue.front();
                myqueue.pop();
                
                int i_ = ele.first;
                int j_ = ele.second;
                
                for (const pair<int, int>& p : tmp) {
                    int new_i = i_ + p.first;
                    int new_j = j_ + p.second;
                    if (new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid.front().size()) continue;
                    if (grid[new_i][new_j] == 1) continue;
                    if (visited.count({new_i, new_j}) > 0) continue;
                    visited.insert({new_i, new_j});
                    myqueue.push({new_i, new_j});
                    res = dis;
                }
            }
            
            dis++;
        }
        
        return res;
    }
};

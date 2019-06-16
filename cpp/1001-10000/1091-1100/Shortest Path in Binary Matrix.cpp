class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        set<pair<int, int>> visited;
        
        visited.insert({0, 0});
        queue<pair<pair<int, int>, int>> myqueue;
        myqueue.push({{0, 0}, 1});
        
        while (!myqueue.empty()) {
            auto ele = myqueue.front();
            myqueue.pop();
            int m_ = ele.first.first;
            int n_ = ele.first.second;
            int d = ele.second;
            
            if (m_ == m - 1 && n_ == n - 1) return d;
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 1 && j == 1) continue;
                    int new_m = m_ + i - 1;
                    int new_n = n_ + j - 1;
                    if (new_m < 0 || new_n < 0 || new_m >= m || new_n >= n) continue;
                    if (visited.count({new_m, new_n}) > 0) continue;
                    if (grid[new_m][new_n] == 1) continue;
                    visited.insert({new_m, new_n});
                    myqueue.push({{new_m, new_n}, d+1});
                }
            }
        }
        
        return -1;
    }
};

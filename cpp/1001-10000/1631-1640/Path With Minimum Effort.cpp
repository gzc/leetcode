class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        auto cmp = [](const pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> myqueue(cmp);
        myqueue.push({0, {0, 0}});
        set<pair<int, int>> visited;
        
        while (!myqueue.empty()) {
            pair<int, pair<int, int>> cur = myqueue.top();
            myqueue.pop();
            int height = cur.first;
            pair<int, int> pos = cur.second;
            if (pos.first == m-1 && pos.second == n-1) return height;
            if (visited.count(cur.second) > 0) continue;
            visited.insert(cur.second);
            
            pair<int, int> dirs[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for (pair<int, int> dir : dirs) {
                int pos_x = pos.first + dir.first;
                int pos_y = pos.second + dir.second;
                if (pos_x < 0 || pos_x >= m || pos_y < 0 || pos_y >= n) continue;
                int new_height = max(height, abs(heights[pos_x][pos_y] - heights[pos.first][pos.second]));
                myqueue.push({new_height, {pos_x, pos_y}});
            }
        }
        
        return -1;
    }
};

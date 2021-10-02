class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> myqueue;
        unordered_set<int> visited;
        myqueue.push({0, 0});
        visited.insert(0);
        
        int step = 0;
        vector<pair<int, int>> directions = {{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1}};
        
        while (!myqueue.empty()) {
            
            int k = myqueue.size();
            
            for (int i = 0; i < k; i++) {
                pair<int, int> cur = myqueue.front();
                myqueue.pop();
                
                if (cur.first == x && cur.second == y) {
                    return step;
                }
                
                for (const auto& d : directions) {
                    int nx = cur.first + d.first;
                    int ny = cur.second + d.second;
                    if (nx < -300 || ny < -300 || ny > 300 || nx > 300) continue;
                    if ((abs(nx) + abs(ny)) > 300) continue;
                    
                    int key = nx * 1000 + ny;
                    
                    if (visited.count(key) > 0) continue;
                    
                    visited.insert(key);
                    myqueue.push({nx, ny});
                }
            }
            
            step++;
        }
        
        return step;
    }
};

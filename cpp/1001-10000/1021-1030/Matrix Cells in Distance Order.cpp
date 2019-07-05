class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> myqueue;
        myqueue.push_back({r0, c0});
        int i = 0;
        int dis = 0;
        
        pair<int, int> tmp[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (i < myqueue.size()) {
            int next_i = myqueue.size();
            dis++;
            unordered_set<int> visited;
            
            for (int k = i; k < next_i; k++) {
                
                int x = myqueue[k][0];
                int y = myqueue[k][1];
                
                for (int j = 0; j < 4; j++) {
                    int n_x = x + tmp[j].first;
                    int n_y = y + tmp[j].second;
                    if (n_x < 0 || n_y < 0 || n_x >= R || n_y >= C) continue;
                    int d = abs(r0 - n_x) + abs(c0 - n_y);
                    if (dis != d) continue;
                    int hash_ = n_x * 101 + n_y;
                    if (visited.count(hash_) > 0) continue;
                    myqueue.push_back({n_x, n_y});
                    visited.insert(hash_);
                }
                
            }
            
            i = next_i;
        }
        
        return myqueue;
    }
};

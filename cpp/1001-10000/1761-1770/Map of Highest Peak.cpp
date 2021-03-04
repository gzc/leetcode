class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater.front().size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        
        queue<pair<int, int>> myqueue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    myqueue.push({i, j});
                    result[i][j] = 0;
                }
            }
        }
        
        int cur_height = 0;
        while (!myqueue.empty()) {
            int total = myqueue.size();
            
            for (int k = 0; k < total; k++) {
                pair<int, int> pos = myqueue.front();
                myqueue.pop();
                
                pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (pair<int, int> direction : directions) {
                    int new_pos_x = pos.first + direction.first;
                    int new_pos_y = pos.second + direction.second;
                    if (new_pos_x < 0 || new_pos_x >= m|| new_pos_y < 0 || new_pos_y >= n
                        || result[new_pos_x][new_pos_y] != -1) {
                        continue;
                    }
                    myqueue.push({new_pos_x, new_pos_y});
                    result[new_pos_x][new_pos_y] = cur_height + 1;
                }
            }
            
            cur_height++;
        }
        
        return result;
    }
};

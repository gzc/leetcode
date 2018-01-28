class Solution {
    
    int seralize(vector<vector<int>>& board) {
        int result = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                result = result * 10 + board[i][j];
            }
        }
        return result;
    }
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int goal = 123450;
        int mi = 0, mj = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    mi = i;
                    mj = j;
                }
            }
        }
        
        queue<pair<int, vector<vector<int>>>>myqueue;
        myqueue.push({0, board});
        set<int>visited;
        
        while (!myqueue.empty()) {
            pair<int, vector<vector<int>>> e = myqueue.front();
            myqueue.pop();
            int key = seralize(e.second);
            if (key == goal) {
                return e.first;
            }
            if (visited.count(key) > 0) continue;
            visited.insert(key);
            vector<vector<int>> myboard = e.second;
            
            int ii, jj;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (myboard[i][j] == 0) {
                        ii = i;
                        jj = j;
                    }
                }
            }
            
            pair<int, int> mypair[4] = {{1,0}, {-1, 0}, {0,-1}, {0,1}};
            for (int i = 0; i < 4; i++) {
                int ni = ii + mypair[i].first;
                int nj = jj + mypair[i].second;
                if (ni < 0 || nj < 0 || ni >= 2 || nj >= 3) continue;
                vector<vector<int>> Tboard = myboard;
                Tboard[ii][jj] = Tboard[ni][nj];
                Tboard[ni][nj] = 0;
                myqueue.push({e.first + 1, Tboard});
            }
        }
        
        return -1;
    }
};

class Solution {
    
    int isStone(vector<vector<int>>& maze, int i, int j) {
        int N1 = maze.size();
        int N2 = maze[0].size();
        if (i < 0 || j < 0 || i >= N1 || j >= N2) return 1;
        return maze[i][j];
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        queue<pair<int,int>> myqueue;
        set<pair<int,int>> visited;
        myqueue.push({start[0], start[1]});
        visited.insert({start[0], start[1]});
        pair<int, int> directions[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!myqueue.empty()) {
            pair<int, int> pos = myqueue.front();
            myqueue.pop();
            if (pos.first == destination[0] && pos.second == destination[1])
                return true;

            for (int i = 0;i < 4;i++) {
                int nx = pos.first;
                int ny = pos.second;
                while (!isStone(maze, nx, ny)) {
                    nx += directions[i].first;
                    ny += directions[i].second;
                }
                nx -= directions[i].first;
                ny -= directions[i].second;
                pair<int, int> n_pos{nx, ny};
                if (visited.count(n_pos) == 0) {
                    myqueue.push(n_pos);
                    visited.insert(n_pos);
                }
            }
            
        }
        
        return false;
    }
};

class Solution {
    
    int isStone(vector<vector<int>>& maze, int i, int j) {
        int N1 = maze.size();
        int N2 = maze[0].size();
        if (i < 0 || j < 0 || i >= N1 || j >= N2) return 1;
        return maze[i][j];
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        queue<pair<int,int>> myqueue;
        map<pair<int,int>, int> distance;
        myqueue.push({start[0], start[1]});
        distance[{start[0], start[1]}] = 0;
        pair<int, int> directions[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!myqueue.empty()) {
            pair<int, int> pos = myqueue.front();
            myqueue.pop();

            for (int i = 0;i < 4;i++) {
                int nx = pos.first;
                int ny = pos.second;
                int step = 0;
                while (!isStone(maze, nx, ny)) {
                    nx += directions[i].first;
                    ny += directions[i].second;
                    step++;
                }
                nx -= directions[i].first;
                ny -= directions[i].second;
                step--;
                pair<int, int> n_pos{nx, ny};
                if (distance.count(n_pos) == 0 || distance[pos] + step < distance[n_pos]) {
                    myqueue.push(n_pos);
                    distance[n_pos] = distance[pos] + step;
                }
            }
            
        }
        
        return distance[{destination[0], destination[1]}] == 0 ? -1 : distance[{destination[0], destination[1]}];
        
    }
};

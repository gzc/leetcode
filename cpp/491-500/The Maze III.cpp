class Solution {
    
    int isStone(vector<vector<int>>& maze, int i, int j) {
        int N1 = maze.size();
        int N2 = maze[0].size();
        if (i < 0 || j < 0 || i >= N1 || j >= N2) return 1;
        return maze[i][j];
    }
    
    
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        queue<pair<int,int>> myqueue;
        map<pair<int,int>, pair<int,string>> distance;
        myqueue.push({ball[0], ball[1]});
        distance[{ball[0], ball[1]}] = {0, ""};
        pair<int, int> directions[4] = {{1,0},{0,-1},{0,1},{-1,0}};
        string dis = "dlru";
        
        string res = "impossible";
        int minimum_distance = INT_MAX;
        
        while (!myqueue.empty()) {
            pair<int, int> pos = myqueue.front();
            myqueue.pop();

            for (int i = 0;i < 4;i++) {
                int nx = pos.first;
                int ny = pos.second;
                int step = 0;
                while (!isStone(maze, nx, ny)) {
                    if (nx == hole[0] && ny == hole[1]) {
                        if (minimum_distance > distance[pos].first + step) {
                            minimum_distance = distance[pos].first + step;
                            res = distance[pos].second + dis[i];
                        } else if (minimum_distance == distance[pos].first + step) {
                            res = min(res, distance[pos].second + dis[i]);
                        }
                    }
                    nx += directions[i].first;
                    ny += directions[i].second;
                    step++;
                }
                nx -= directions[i].first;
                ny -= directions[i].second;
                step--;
                pair<int, int> n_pos{nx, ny};
                if (distance.count(n_pos) == 0 || distance[pos].first + step < distance[n_pos].first) {
                    myqueue.push(n_pos);
                    distance[n_pos].first = distance[pos].first + step;
                    distance[n_pos].second = distance[pos].second + dis[i];
                } else if (distance[pos].first + step == distance[n_pos].first) {
                    if (distance[pos].second + dis[i] < distance[n_pos].second) {
                        distance[n_pos].second = distance[pos].second + dis[i];
                        myqueue.push(n_pos);
                    }
                }
            }
            
        }
        
        return res;
    }
};

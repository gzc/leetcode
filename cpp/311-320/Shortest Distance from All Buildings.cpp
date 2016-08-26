struct point {
    int i;
    int j;
    int v;
    point(int _i, int _j, int _v){i = _i; j = _j; v = _v;}
};

class Solution {
    
    void BFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& records) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        
        queue<struct point> myqueue;
        point cur(i, j, 0);
        myqueue.push(cur);
        visited[i][j] = true;
        
        while (!myqueue.empty()) {
            cur = myqueue.front();
            myqueue.pop();
            
            if(records[cur.i][cur.j] >= 0)
                records[cur.i][cur.j] += cur.v;
            
            pair<int,int> pos[4] = {{-1,0},{1,0},{0,1},{0,-1}};
            
            for (int k = 0;k < 4;k++) {
                int curi = cur.i + pos[k].first;
                int curj = cur.j + pos[k].second;
                
                if (curi >= 0 && curi < m && curj >= 0 && curj < n && !visited[curi][curj] &&
                grid[curi][curj] == 0 && records[curi][curj] >= 0) {
                    point p(curi, curj, cur.v+1);
                    visited[curi][curj] = true;
                    myqueue.push(p);
                }
            }
        }
    
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                if (!visited[i][j])
                    records[i][j] = INT_MIN;
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > records(m, vector<int>(n, 0));
        
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(grid[i][j] == 1)
                    BFS(i, j, grid, records);
        
        int result(INT_MAX);
        
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(records[i][j] > 0)
                    result = min(result, records[i][j]);
        
        if(result == INT_MAX) return -1;
        return result;
    }
    
};

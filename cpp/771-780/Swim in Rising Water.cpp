class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = 0;
        auto cmp = [](const pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
            return a.first > b.first;
        };
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
        
        pair<int, pair<int, int>> start{grid[0][0], {0, 0}};
        pq.push(start);
        
        set<int> visited;
        
        while (!pq.empty()) {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();
            ans = max(ans, current.first);
            visited.insert(current.second.first * 10000 + current.second.second);
            
            if(current.second.first == N - 1 && current.second.second == N - 1) {
                break;
            }
            
            pair<int, int> mypair[4] = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
            for (pair<int, int> pos : mypair) {
                int nexti = current.second.first + pos.first;
                int nextj = current.second.second + pos.second;
                if (nexti < 0 || nextj < 0 || nexti >= N || nextj >= N) continue;
                if (visited.count(nexti * 10000 + nextj) > 0) continue;
                pq.push({grid[nexti][nextj], {nexti, nextj}});
            }
        }
        
        return ans;
    }
};

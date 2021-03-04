class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n+1);
        
        for (const vector<int>& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            const unordered_set<int>& neighbors = graph[i];
            int tmp_a = graph[i].size() - 2;
            if (tmp_a >= ans) {
                continue;
            }
            for (int b : neighbors) {
                int tmp_b = tmp_a + graph[b].size() - 2;
                if (b < i || tmp_b >= ans) {
                    continue;
                }
                for (int c : graph[b]) {
                    if (neighbors.count(c) > 0) {
                        ans = min(ans, tmp_b + (int)graph[c].size() - 2);
                    }
                } 
            }
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};

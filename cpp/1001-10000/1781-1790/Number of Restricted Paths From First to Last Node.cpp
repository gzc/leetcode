class Solution {
public:
    
    void bfs(int n, const vector<vector<pair<int, int>>>& graph, vector<int>& distances, vector<int>& closest_nodes) {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<bool> visited(n+1, false);
        pq.push({n, 0});
        
        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();
            int node = current.first;
            int dis = current.second;
            if (visited[node] == true) {
                continue;
            }
            distances[node] = dis;
            visited[node] = true;
            closest_nodes.push_back(node);
            
            for (pair<int, int> neighbor : graph[node]) {
                int neighbor_node = neighbor.first;
                if (visited[neighbor_node] == false) {
                    pq.push({neighbor_node, dis + neighbor.second});
                }
            }
        }
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> distances(n + 1, 0);
        vector<int> closest_nodes;
        bfs(n, graph, distances, closest_nodes);
        
        vector<long> dp(n+1, 0);
        dp[1] = 1;
        int mod = 1e9+7;
        for (int i = closest_nodes.size() - 1; i >= 0; i--) {
            int node = closest_nodes[i];
            for (pair<int, int> neighbor : graph[node]) {
                int neighbor_node = neighbor.first;
                if (distances[neighbor_node] < distances[node]) {
                    dp[neighbor_node] += dp[node];
                    dp[neighbor_node] %= mod;
                }
            }
        }
        
        return dp[n];
    }
};

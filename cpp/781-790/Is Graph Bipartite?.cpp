class Solution {
    
    bool dfs(int node, vector<bool>& visited, vector<bool>& colors, const vector<vector<int>>& graph, bool c) {
        visited[node] = true;
        colors[node] = c;
        bool flag = true;
        for (int neighbor : graph[node]) {
            if (visited[neighbor]) {
                if (colors[neighbor] == c) {
                    return false;
                }
            } else {
                flag = dfs(neighbor, visited, colors, graph, !c);
            }
        }
        return flag;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> colors(n, false);
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if(!dfs(i, visited, colors, graph, false)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

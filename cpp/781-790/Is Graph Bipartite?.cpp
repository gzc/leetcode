class Solution {
    
    bool dfs(int node, vector<int>& colors, const vector<vector<int>>& graph, int c) {
        colors[node] = c;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == c) {
                return false;
            }
            if (colors[neighbor] == 0 && !dfs(neighbor, colors, graph, 3 - c)) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        
        for (int i = 0; i < n; i++)
            if (colors[i] == 0)
                if(!dfs(i, colors, graph, 1))
                    return false;
        
        return true;
    }
};

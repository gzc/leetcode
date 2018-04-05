class Solution {
    
    bool dfs(int i, const vector<vector<int>>& graph, vector<int>& colors) {
        if (colors[i] == 2) return true;
        if (colors[i] == 1) return false;
        
        colors[i] = 1;
        for (int v : graph[i]) {
            if (!dfs(v, graph, colors)) {
                return false;  
            }
        }
        
        colors[i] = 2;
        return true;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        vector<int> ans;
        
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(i, graph, colors)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

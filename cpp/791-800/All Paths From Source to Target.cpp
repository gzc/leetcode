class Solution {
    
    void dfs(int current, int target, vector<int> path, const vector<vector<int>>& graph, vector<vector<int>>& result) {
        if (current == target) {
            result.emplace_back(path);
            return;
        }
        
        for (int e : graph[current]) {
            vector<int> pathCopy(path);
            pathCopy.push_back(e);
            dfs(e, target, pathCopy, graph, result);
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int n = graph.size();
        vector<int> vec{0};
        
        dfs(0, n-1, vec, graph, result);
        
        return result;
    }
};

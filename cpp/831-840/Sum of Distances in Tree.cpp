class Solution {
    
    int dfs(int start, vector<int>& myNodes, vector<bool>& visited, map<int, vector<int>>& graph, int level, int& res) {
        visited[start] = true;
        
        int nodeNum = 1;
        for (int neig : graph[start]) {
            if (visited[neig]) continue;
            nodeNum += dfs(neig, myNodes, visited, graph, level+1, res);
        }
        myNodes[start] = nodeNum;
        res += level;
        return nodeNum;
    }
    
    void dfs2(int start, vector<int>& myNodes, map<int, vector<int>>& graph, vector<int>& ans, int distanceOfStart) {
        if (ans[start] < 0) {
            int mine = myNodes[start] - 1;
            int other =myNodes.size() - mine - 2;
            ans[start] = distanceOfStart + (other - mine);
        }
        
        for (int neig : graph[start]) {
            if (ans[neig] > 0) continue;
            dfs2(neig, myNodes, graph, ans, ans[start]);
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int distanceOfStart = 0;
        vector<int> myNodes(N, 0);
        vector<bool> visited(N, false);
        dfs(0, myNodes, visited, graph, 0, distanceOfStart);
        
        
        vector<int> ans(N, -1);
        ans[0] =distanceOfStart;
        dfs2(0, myNodes, graph, ans, distanceOfStart);
        
        return ans;
    }
};

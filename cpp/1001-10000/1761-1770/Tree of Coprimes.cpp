class Solution {
    
    void dfs(int node, const vector<int>& nums, const vector<vector<int>>& graph,
             vector<int>& result,
             map<int, pair<int, int>>& ancestors /*value, {node, depth}*/,
             int depth, int parent) {
        int closest_ancestor = -1;
        int distance = INT_MAX;
        for (const auto& pair : ancestors) {
            if (__gcd(nums[node], pair.first) == 1 && (depth - pair.second.second) < distance) {
                distance = depth - pair.second.second;
                closest_ancestor = pair.second.first;
            }
        }
        result[node] = closest_ancestor;
        
        bool has_original_node = (ancestors.count(nums[node])) > 0;
        pair<int, int> original_node = ancestors[nums[node]];
        ancestors[nums[node]] = {node, depth};
        for (int neighbor : graph[node]) {
            if (neighbor == parent) {
                continue;
            }
            dfs(neighbor, nums, graph, result, ancestors, depth + 1, node);
        }
        ancestors.erase(nums[node]);
        if (has_original_node) {
            ancestors[nums[node]] = original_node;
        }
    }
    
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        map<int, pair<int, int>> ancestors;
        vector<int> result(n, -1);
        dfs(/*node=*/0, nums, graph, result, ancestors, /*depth=*/0, /*parent=*/-1);
        return result;
    }
};

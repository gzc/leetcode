class Solution {
    
    void dfs(int node, vector<int>& group, vector<int>& colors, map<int, vector<int>>& graph) {
        colors[node] = 1;
        group.push_back(node);
        
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == 0) {
                dfs(neighbor, group, colors, graph);
            }
        }
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        map<int, vector<int>> graph;
        for (const auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        int n = s.length();
        vector<int> colors(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                vector<int> group;
                dfs(i, group, colors, graph);
                sort(group.begin(), group.end());
                
                string temp;
                for (int index : group) temp += s[index];
                sort(temp.begin(), temp.end());
                for (int k = 0; k < group.size(); k++) {
                    s[group[k]] = temp[k];
                }
            }
        }
        
        return s;
    }
};

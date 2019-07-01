class Solution {
    vector<int> colors;
    
    void dfs(int u, map<int, vector<int>>& edges) {
        vector<int> neighbors = edges[u];
        set<int> excluded_colors;
        for (int neighbor : neighbors) {
            if (colors[neighbor-1] > 0) {
                excluded_colors.insert(colors[neighbor-1]);   
            }
        }
        
        for (int i = 1; i <= 4; i++) {
            if (excluded_colors.count(i) == 0) {
                colors[u-1] = i;
                for (int neighbor : neighbors) {
                    if (colors[neighbor-1] == 0) {
                        dfs(neighbor, edges);
                    }   
                }
                break;
            }
        }
    }
    
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        map<int, vector<int>> edges;
        for (const vector<int>& path : paths) {
            edges[path[0]].push_back(path[1]);
            edges[path[1]].push_back(path[0]);
        }
        colors.resize(N, 0);
        
        for (int garden = 1; garden <= N; garden++) {
            if (colors[garden - 1] == 0) {
                dfs(garden, edges);
            }
        }
        
        return colors;
    }
};

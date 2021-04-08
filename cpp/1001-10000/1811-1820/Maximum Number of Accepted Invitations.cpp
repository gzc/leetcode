class Solution {
    int m, n;
public:
    bool BipartiteMatch(const vector<vector<int>>& grid, int u, vector<bool>& visited, vector<int>& girls) {
        for (int v = 0; v < n; v++) {
            if (grid[u][v] == 0 || visited[v]) {
                continue;
            }
            
            visited[v] = true;
            if (girls[v] < 0 || BipartiteMatch(grid, girls[v], visited, girls)) {
                girls[v] = u;
                return true;
            }
       }
        
       return false;
    }
    
    int maximumInvitations(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<int> grils(n, -1);
        int matches = 0;

        for (int u = 0; u < m; u++) {
            vector<bool> visited(n, false);
            if (BipartiteMatch(grid, u, visited, grils)) {
                matches++;
            }
        }
        return matches;
    }
};

class Solution {
    void dfs(int u, const vector<vector<int>>& rooms, vector<bool>& visited) {
        for (int v : rooms[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dfs(v, rooms, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n < 2) return true;
        vector<bool> visited(n, false);
        visited[0] = true;
        
        dfs(0, rooms, visited);
        
        for (bool b : visited) {
            if (!b) return false;
        }
        return true;
    }
};

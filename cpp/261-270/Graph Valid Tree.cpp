class Solution {
    
    int findParent(const vector<int>& vec, int node) {
        while (node != vec[node]) {
            node = vec[node];
        }
        
        return node;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() + 1 != n) {
            return false;
        }
        
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++) {
            vec[i] = i;
        }
        
        for (const vector<int>& edge : edges) {
            int p1 = findParent(vec, edge[0]);
            int p2 = findParent(vec, edge[1]);
            if (p1 == p2) return false;
            vec[p1] = p2;
        }
        
        return true;
    }
};

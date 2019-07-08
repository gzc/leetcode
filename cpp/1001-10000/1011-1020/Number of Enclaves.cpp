class Solution {
    
    pair<int, int> tmp[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int m;
    int n;
    
    void dfs(vector<vector<int>>& A, int i, int j) {
        if (A[i][j] == 0) return;
        A[i][j] = 2;
        for (int k = 0; k < 4; k++) {
            int n_i = i + tmp[k].first;
            int n_j = j + tmp[k].second;
            if (n_i < 0 || n_j < 0 || n_i >= m || n_j >= n) continue;
            if (A[n_i][n_j] == 1) dfs(A, n_i, n_j);
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size();
        n = A.front().size();
        
        for (int i = 0; i < m; i++) {
            dfs(A, i, 0);
            dfs(A, i, n-1);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(A, 0, j);
            dfs(A, m-1, j);
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

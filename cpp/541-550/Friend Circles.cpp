class Solution {
public:
    void dfs(int i, vector<vector<int>>& M, vector<int>& colors) {
        colors[i] = 1;
        int m = M.size();
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) continue;
            if (colors[j] == 0) {
                dfs(j, M, colors);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        if (m == 0) return 0;
        int res = 0;
        vector<int> colors(m, 0);
        for (int i = 0; i < m; i++) {
            if (colors[i] == 0) {
                res++;
                dfs(i, M, colors);
            }
        }
        return res;
    }
};

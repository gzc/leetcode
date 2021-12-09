class Solution {
    
    int DFS(vector<bool> &vis, vector<vector<int>> &skip, int cur, int remain) {
        if(remain == 0) return 1;
        vis[cur] = true;
        int rst = 0;
        for (int i = 1; i <= 9; ++i) {
            if(!vis[i] && (skip[i][cur] == 0 || (vis[skip[i][cur]]))) {
                rst += DFS(vis, skip, i, remain - 1);
            }
        }
        vis[cur] = false;
        return rst;
    }

public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        vector<bool> vis(10);
        int rst = 0;
        // DFS search each length from m to n
        for(int i = m; i <= n; ++i) {
            rst += DFS(vis, skip, 1, i - 1) * 4;    // 1, 3, 7, 9 are symmetric
            rst += DFS(vis, skip, 2, i - 1) * 4;    // 2, 4, 6, 8 are symmetric
            rst += DFS(vis, skip, 5, i - 1);        // 5
        }
        return rst;
    }
};

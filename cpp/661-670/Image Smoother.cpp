class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int gray = 0;
                int total = 0;
                for (int k1 = -1; k1 <= 1; k1++) {
                    for (int k2 = -1; k2 <= 1; k2++) {
                        int newi = i + k1;
                        int newj = j + k2;
                        if (newi < 0 || newj < 0 || newi >= m || newj >= n) continue;
                        total++;
                        gray += M[newi][newj];
                    }
                }
                result[i][j] = gray / total;
            }
        }
        return result;
    }
};

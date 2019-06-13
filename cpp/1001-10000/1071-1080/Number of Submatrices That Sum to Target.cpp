class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> counter;
                counter[0] = 1;
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += counter[cur - target];
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix[0].size() -1;
        for (int i = 0;i <= n - i;i++) {
            for (int j = i;j <= n - i - 1;j++) {
                int tmp = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = tmp;
            }
        }
    }
};

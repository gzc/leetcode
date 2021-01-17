class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int j = 0; j < n; j++) {
            for (int i = m-1; i >= 0; i--) {
                if (matrix[i][j] == 1 && i != (m-1)) {
                    matrix[i][j] = 1 + matrix[i+1][j];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), std::greater<int>());
            
            for (int w = 0; w < matrix[i].size(); w++) {
                if (matrix[i][w] == 0) break;
                ans = max(ans, (w+1) * matrix[i][w]);
            }
        }
        
        return ans;
    }
};

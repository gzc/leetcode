class Solution {
    
    bool check(const vector<vector<long>>& sum, int side_length, int m, int n, int threshold) {
        for (int i = 0; i <= m-side_length; i++) {
            for (int j = 0; j <= n-side_length; j++) {
                int x = i + side_length;
                int y = j + side_length;
                long current_sum = sum[x][y] - sum[i][y] - sum[x][j] + sum[i][j];
                if (current_sum <= threshold) return true;
            }
        }
        return false;
    }
    
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<long>> sum(m+1, vector<long>(n+1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + mat[i][j];
            }
        }
        
        int left = 1; int right = min(m, n);
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            bool ok = check(sum, mid, m, n, threshold);
            if (ok) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

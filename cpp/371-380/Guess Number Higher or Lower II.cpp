class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>table(n+1, vector<int>(n+1,0));
        for (int j = 2;j <= n; j++) {
            for (int i = j-1; i > 0; i--) {
                int temp_min = INT_MAX;
                for (int k = i; k < j; k++) {
                    int localMax = k + max(table[i][k==i?k:k-1], table[k+1][j]);
                    temp_min = min(temp_min, localMax);
                }
                table[i][j] = temp_min;
            }
        }
        return table[1][n];
    }
};

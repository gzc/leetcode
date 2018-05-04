class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) return vector<int>();
        int m = matrix.size();
        int n = matrix.front().size();
        int total = m * n;
        vector<int> ans(total);
        bool up = true;
        int i = 0, j = 0;
        
        for (int k = 0; k < total; k++) {
            ans[k] = matrix[i][j];
            
            if (up && (i == 0 || j == n - 1)) {
                if (j == n - 1) i++;
                else j++;
                up = !up;
            }
            else if (!up && (j == 0 || i == m - 1)) {
                if (i == m - 1) j++;
                else i++;
                up = !up;
            } else {
                if (up) { i--; j++; }
                else { i++; j--; }
            }
        }
        
        return ans;
    }
};

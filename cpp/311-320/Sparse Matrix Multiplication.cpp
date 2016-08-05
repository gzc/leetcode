class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row1 = A.size();
        int col1 = A[0].size();
        int row2 = B.size();
        int col2 = B[0].size();
        
        vector<vector<int>> res(row1, vector<int>(col2, 0));
        vector<unordered_map<int,int>> CacheB(col2);
        
        for (int i = 0;i < row2;i++)
            for (int j = 0;j < col2;j++)
                if (B[i][j] != 0)
                    CacheB[j][i] = B[i][j];
        
        for (int i = 0;i < row1;i++) {
            for (int j = 0;j < col2;j++) {
                unordered_map<int, int> right = CacheB[j];
                if (right.size() == 0) continue;
                for (int k = 0;k < col1;k++) {
                    if (A[i][k] != 0 && right.count(k) > 0) {
                        res[i][j] += A[i][k] * right[k];
                    }
                }
            }
        }
        
        return res;
    }
};

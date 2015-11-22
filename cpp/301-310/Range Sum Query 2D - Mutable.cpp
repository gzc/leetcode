class NumMatrix {
    
    vector<vector<int>> dp;
    vector<vector<int>> matrix;
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        
        for(int i = 0;i < matrix.size();i++) {
            vector<int> temp(matrix[0].size()+1,0);
            for(int j = 0;j < matrix[0].size();j++) {
                temp[j+1] = temp[j] + matrix[i][j];
            }
            dp.push_back(temp);
        }
        
        this->matrix = matrix;
    }
    
    void update(int row, int col, int val) {
        for(int j = col;j < matrix[0].size();j++) {
            dp[row][j+1] = dp[row][j+1] - matrix[row][col] + val;
        }
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1;i <= row2;i++) {
            res += (dp[i][col2+1] - dp[i][col1]);
        }
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
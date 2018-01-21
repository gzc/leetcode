class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int r = 0; r < matrix.size(); r++)
            for (int c = 0; c < matrix[0].size(); c++)
                if (r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c])
                    return false;
        return true;
    }
};

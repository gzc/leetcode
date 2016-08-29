class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row(matrix.size()), col(matrix[0].size());
        int i(0), j(row*col-1);
        while (i <= j) {
            int mid = (i+j) >> 1;
            int v = matrix[mid/col][mid%col];
            if (target < v) j = mid  - 1;
            else if (target > v) i = mid + 1;
            else if (target == v) return true;
        }
        return false;
    }
};

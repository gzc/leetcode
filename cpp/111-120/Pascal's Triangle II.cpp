class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for (int row = 0; row < rowIndex; row++) {
            for (int col = row; col > 0; col--) {
                result[col] += result[col - 1];
            }
        }
        return result;
    }
};

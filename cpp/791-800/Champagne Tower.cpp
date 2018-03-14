class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> myvec (query_row+2, vector<double>(query_row+3, 0));
        myvec[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double overflow = fmax(myvec[i][j] - 1, 0);
                myvec[i][j] -= overflow;
                myvec[i+1][j] += overflow/2;
                myvec[i+1][j+1] += overflow/2;
            }
        }
        return myvec[query_row][query_glass];
    }
};

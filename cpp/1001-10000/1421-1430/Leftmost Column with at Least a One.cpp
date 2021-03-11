/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int row = dimension[0];
        int col = dimension[1];
        int res = -1;
        for (int i = 0; i < row; i++) {
            int left = 0;
            int right = (res == -1 ? col - 1 : res - 1);
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (binaryMatrix.get(i, mid) == 0) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            if (binaryMatrix.get(i, left) == 1) {
                res = left;
            }
        }
        return res;
    }
};

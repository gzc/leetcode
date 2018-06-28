class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int L = matrix[0][0], R = matrix[n - 1][n - 1];
		while (L < R) {
			int mid = L + ((R - L) >> 1);
			int temp = search_lower_than_mid(matrix, mid);
			if (temp < k) L = mid + 1;
			else R = mid;
		}
		return L;
	}
	int search_lower_than_mid(const vector<vector<int>>& matrix, int x) {
        int n = matrix.size();
		int i = n - 1, j = 0, cnt = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] <= x) {
				j++;
				cnt += i + 1;
			}
			else i--;
		}
		return cnt;
	}
};

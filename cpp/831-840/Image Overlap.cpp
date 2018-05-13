class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || A.front().empty()) {
            return 0;
        }
        
        int n = A.size();
        int res = 0;
        for (int i = 1 - n; i <= n -1; i++) {
            for (int j = 1-n; j <= n-1; j++) {
                int cur = 0;
                for (int k = max(i, 0); k < min(i + n, n); k++) {
                    for (int l = max(j, 0); l < min(j + n, n); l++) {
                        if (A[k -i][l - j] == 1 && B[k][l] == 1) {
                            cur ++;
                        }
                    }
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};

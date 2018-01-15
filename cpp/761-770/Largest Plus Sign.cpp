class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        set<pair<int, int>> myset;
        for (const auto& mine : mines) {
            myset.insert({mine[0], mine[1]});
        }
        
        vector<vector<int>> left (N, vector<int>(N, 0));
        vector<vector<int>> right (N, vector<int>(N, 0));
        vector<vector<int>> up (N, vector<int>(N, 0));
        vector<vector<int>> down (N, vector<int>(N, 0));
        
        for (int i = 0; i < N; i++) {
            int temp = 0;
            for (int j = 0; j < N; j++) {
                if (myset.count({i, j}) > 0) {
                    temp = 0;
                } else {
                    temp++;
                }
                left[i][j] = temp;
            }
        }
        
        for (int i = 0; i < N; i++) {
            int temp = 0;
            for (int j = N-1; j >= 0; j--) {
                if (myset.count({i, j}) > 0) {
                    temp = 0;
                } else {
                    temp++;
                }
                right[i][j] = temp;
            }
        }
        
        for (int i = 0; i < N; i++) {
            int temp = 0;
            for (int j = 0; j < N; j++) {
                if (myset.count({j, i}) > 0) {
                    temp = 0;
                } else {
                    temp++;
                }
                up[j][i] = temp;
            }
        }
        
        for (int i = 0; i < N; i++) {
            int temp = 0;
            for (int j = N-1; j >= 0; j--) {
                if (myset.count({j, i}) > 0) {
                    temp = 0;
                } else {
                    temp++;
                }
                down[j][i] = temp;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int current = min(left[i][j], right[i][j]);
                current = min(up[i][j], current);
                current = min(down[i][j], current);
                ans = max(ans, current);
            }
        }
        
        return ans;
    }
};

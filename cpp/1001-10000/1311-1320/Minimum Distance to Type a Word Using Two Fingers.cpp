class Solution {
    
    int distance(int from, int to) {
        if (from == 26) return 0;
        int row_1 = from / 6;
        int col_1 = from%6;
        int row_2 = to / 6;
        int col_2 = to%6;
        return abs(row_1 - row_2) + abs(col_1 - col_2);
    }
    
    int dfs(vector<vector<vector<int>>>& dp, const string& word, int index, int left, int right) {
        if (index >= word.length()) return 0;
        if (dp[left][right][index] != 0) return dp[left][right][index];
        char ch = word[index];
        int chv = ch - 'A';
        
        int temp = min(dfs(dp, word, index+1, chv, right) + distance(left, chv),
                      dfs(dp, word, index+1, left, chv) + distance(right, chv));
        return dp[left][right][index] = temp;
    }
    
public:
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(301, 0)));
        return dfs(dp, word, 0, 26, 26);
    }
};

class Solution {
public:
    bool dfs(vector<vector<char>>& board, const string &word, int i, int j, int ind) {
        if (ind == word.size()) {
            return true;
        }
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0) return false;
        if (board[i][j] == 0) return false;
        if (board[i][j] == word[ind]) {
            board[i][j] = 0;
            if (dfs(board, word, i+1, j, ind + 1)) return true;
            if (dfs(board, word, i, j+1, ind + 1)) return true;
            if (dfs(board, word, i-1, j, ind + 1)) return true;
            if (dfs(board, word, i, j-1, ind + 1)) return true;
            board[i][j] = word[ind];
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) { return 0; }
        int m = board.size(), n = board[0].size(), cnt = 0;
        
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                cnt += board[r][c] == 'X' && (r == 0 || board[r - 1][c] != 'X') && (c == 0 || board[r][c - 1] != 'X');
        
        return cnt;
    }
};

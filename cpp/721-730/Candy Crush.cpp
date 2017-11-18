class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        while (true) {
            vector<pair<int,int>> vp;
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (board[i][j]) {
                int i0 = i, i1 = i, j0 = j, j1 = j;
                while (i1 < n &&  i1 < i + 3 && board[i1][j] == board[i][j]) ++i1;
                while (i0 >= 0 && i0 > i - 3 && board[i0][j] == board[i][j]) --i0;
                while (j1 < m && j1 < j + 3 && board[i][j1] == board[i][j]) ++j1;
                while (j0 >= 0 && j0 > j - 3 && board[i][j0] == board[i][j]) --j0;
                if (i1 - i0 >3 || j1 -j0 > 3) vp.push_back({i,j});
            }
            if (vp.empty()) break;
            for (auto p:vp) board[p.first][p.second] = 0;
            for (int j = 0; j < m; ++j) {
                int t = n-1;
                for (int i = n-1; i >=0; --i) if (board[i][j]) swap(board[i][j], board[t--][j]);
            }
        }
        
        return board;
    }
};

class Solution {
    
    void help(vector<vector<char>> &board, int ii, int jj)
    {
        if(board[ii][jj] == 0 || board[ii][jj] == 'X') return;
        board[ii][jj] = 0;
        queue<pair<int,int>>q;
        q.push(make_pair(ii,jj));
        while(!q.empty())
        {
            pair<int,int> cur = q.front(); q.pop();
            pair<int, int> adjs[4] = {{cur.first-1, cur.second}, 
            {cur.first+1, cur.second}, 
            {cur.first, cur.second-1},
            {cur.first, cur.second+1}};
            for (int i = 0; i < 4; ++i)
            {
                int adjW = adjs[i].first;
                int adjL = adjs[i].second;
                if ((adjW >= 0) && (adjW < board.size()) && (adjL >= 0) && (adjL < board[adjW].size()) && (board[adjW][adjL] == 'O'))
                {
                    q.push(make_pair(adjW, adjL));
                    board[adjW][adjL] = 0;
                }
            }
        }
        return;
    }
    
public:
    void solve(vector<vector<char>> &board) {
        
        if(board.size() == 0) return;
        
        for(int i = 0;i < board.size();i++)
        {
            if(board[i].front() == 'O')
                help(board, i, 0);
            if(board[i].back() == 'O')
                help(board, i, board[i].size()-1);
        }
        
        for(int i = 0;i < board[0].size();i++)
        {
            if(board.front()[i] == 'O')
                help(board, 0, i);
            if(board.back()[i] == 'O')
                help(board, board.size()-1, i);
        }
        
        for(int i = 0;i < board.size();i++)
        {
            for(int j = 0;j < board[i].size();j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 0)
                    board[i][j] = 'O';
            }
        }
        
    }
};

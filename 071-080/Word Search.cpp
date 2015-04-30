class Solution {
    
    string::iterator be;
    
    bool help(vector<vector<char> > &board, string::iterator it1, string::iterator it2, int ii, int jj)
    {
        if(it1 == it2)
            return true;
        
        if(it1 == be)
        {
            for(int i = 0;i < board.size();i++)
            {
                for(int j = 0;j < board[i].size();j++)
                {
                    if(board[i][j] == *it1)
                    {
                        board[i][j] = 0;
                        bool t = help(board, it1+1, it2, i, j);
                        board[i][j] = *it1;
                        if(t) return true;
                    }
                }
            }
        }
        else
        {
            for(int d = -1;d <= 1;d = d+2)
            {
                if( (ii+d >= 0) && (ii+d <= board.size()-1)  )
                {
                    if(board[ii+d][jj] == 0) {}
                    else if(board[ii+d][jj] == *it1)
                    {
                        board[ii+d][jj] = 0;
                        bool t = help(board, it1+1, it2, ii+d, jj);
                        board[ii+d][jj] = *it1;
                        if(t) return true;
                    }
                }
                
                if( (jj+d >= 0) && (jj+d <= board[ii].size()-1)  )
                {
                    if(board[ii][jj+d] == 0) {}
                    else if(board[ii][jj+d] == *it1)
                    {
                        board[ii][jj+d] = 0;
                        bool t = help(board, it1+1, it2, ii, jj+d);
                        board[ii][jj+d] = *it1;
                        if(t) return true;
                    }
                }
                
            }
        }
        
        return false;
    }
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        be = word.begin();
        return help(board, word.begin(), word.end(), 0, 0);
    }
    
};

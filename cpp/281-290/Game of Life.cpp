class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int h = board.size();
        int w = board[0].size();
        
        for (int i = 0;i < h;i++)
        {
            for (int j = 0;j < w;j++)
            {
                int old = board[i][j];
                int lives(0);
                int deads(0);
                for (int m = -1;m <= 1;m++)
                {
                    for (int n = -1;n <= 1;n++)
                    {
                        if (m == 0 && n == 0) continue;
                        int ix = j + n;
                        int iy = i + m;
                        if (ix < 0 || iy < 0 || ix >= w || iy >= h) continue;
                        if ( (board[iy][ix] & 0x1) == 0) deads++;
                        else if ( (board[iy][ix] & 0x1) == 1) lives++;
                    }
                }
                
                if (old == 1)
                {
                    if (lives < 2) continue;
                    else if (lives == 2 || lives == 3) board[i][j] |= 0x2;
                    else continue;
                } else {
                    if (lives == 3) board[i][j] |= 0x2;
                }
            }
        }
        
        for (int i = 0;i < h;i++)
        {
            for (int j = 0;j < w;j++)
            {
                if ((board[i][j] & 0x2) > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
        
    }
    
};

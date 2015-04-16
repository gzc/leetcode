#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    
    bool rows[9][9];
    bool cols[9][9];
    bool rec[3][3][9];
    
    bool help(vector<vector<char> > &board, int i, int j)
    {
        if(i == 9) return true;
        
        int nexti = 0;
        int nextj = 0;
        if(j != 8)
        {
            nexti = i;
            nextj = j+1;
        } else {
            nexti = i+1;
            nextj = 0;
        }
        
        if(board[i][j] != '.')
        {
            return help(board, nexti, nextj);
        } else {
            
            for(int k = 0;k < 9;k++)
            {
                if(rows[i][k] == false && cols[k][j] == false && rec[i/3][j/3][k] == false)
                {
                    rows[i][k] = true;
                    cols[k][j] = true;
                    rec[i/3][j/3][k] = true;
                    board[i][j] = (k+'1');
                    bool t = help(board, nexti, nextj);
                    if(t) return true;
                    rows[i][k] = false;
                    cols[k][j] = false;
                    rec[i/3][j/3][k] = false;
                    board[i][j] = '.';
                } else {
                    continue;
                }
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char> > &board) {
        
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(rec, false, sizeof(rec));
        
        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {
                if(board[i][j] != '.')
                {
                    int d = board[i][j] - '1';
                    rows[i][d] = true;
                    cols[d][j] = true;
                    rec[i/3][j/3][d] = true;
                }
            }
        }
        
        help(board, 0, 0);
        
    }
    
};

int main()
{
    Solution s;

    return 0;
}
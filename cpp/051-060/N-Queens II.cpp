class Solution {
    
    bool *cols;
    bool *add;
    bool *diff;
    int n;
    
    bool valid(int i, int j)
    {
        if(!cols[j] && !add[i+j] && !diff[i-j+n])
            return true;
        return false;
    }
    
    void help(int i, int &res)
    {
        if(i == n)
        {
            res++;
            return;
        }

        for(int j = 0;j < n;j++)
        {
            if(valid(i, j))
            {
                cols[j] = add[i+j] = diff[i-j+n] = true;
                help(i+1, res);
                cols[j] = add[i+j] = diff[i-j+n] = false;
            }
        }
    }
    
public:
    int totalNQueens(int n) {

        cols = new bool[n];
        add = new bool[2*n];
        diff = new bool[2*n];
        this->n = n;
        int res = 0;
        
        help(0, res);
        return res;
    }
};

class Solution {
    
    bool *rows;
    bool *cols;
    bool *add;
    bool *diff;
    int n;
    
    bool valid(int i, int j)
    {
        if(!rows[i] && !cols[j] && !add[i+j] && !diff[i-j+n])
            return true;
        return false;
    }
    
    void help(vector<vector<string>> &result, vector<pair<int, int>> &tmp, int i)
    {
        if(i == n)
        {
            if(n == tmp.size())
            {
                string s(n, '.');
                vector<string>t{n,s};
                for(int k = 0;k < tmp.size();k++)
                    t[tmp[k].first][tmp[k].second] = 'Q';
                result.push_back(t);
            }
        } else {
            for(int j = 0;j < n;j++)
            {
                if(valid(i, j))
                {
                    rows[i] = cols[j] = add[i+j] = diff[i-j+n] = true;
                    tmp.push_back(make_pair(i, j));
                    help(result, tmp, i+1);
                    tmp.pop_back();
                    rows[i] = cols[j] = add[i+j] = diff[i-j+n] = false;
                }
            }
        }
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        
        rows = new bool[n];
        cols = new bool[n];
        add = new bool[2*n];
        diff = new bool[2*n];
        this->n = n;
        
        vector<vector<string>> result;
        vector<pair<int, int>> tmp;
        
        help(result, tmp, 0);
        
        return result;
    }
};

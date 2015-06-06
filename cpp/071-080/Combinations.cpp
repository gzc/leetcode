class Solution {
    
    void help(int n, int k, int index, vector<int>&tmp, vector<vector<int>>&v)
    {
        if(k == 0)
        {
            v.push_back(tmp);
            return;
        }
        else if(index > n)
            return;
            
        help(n,k,index+1,tmp,v);
        tmp.push_back(index);
        help(n,k-1,index+1,tmp,v);
        tmp.pop_back();
    }
    
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>>v;
        vector<int>tmp;
        
        help(n,k,1,tmp,v);
        return v;
    }
};

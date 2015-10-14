class Solution {
    
    void help(vector<vector<int>>& result, vector<int>& factors, vector<int> temp, int cur, int n)
    {
        if(n == 1 && temp.size() > 0)
        {
            result.push_back(temp);
            return;
        }
        
        if(cur == factors.size() || n < factors[cur]) return;
        
        if(n % factors[cur] == 0) {
            temp.push_back(factors[cur]);
            help(result, factors, temp, cur, n/factors[cur]);
            temp.pop_back();
        }
        help(result, factors, temp, cur+1, n);
    }
    
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> factors;
        
        for(int i = 2; i <= n/2;i++)
            if(n % i == 0 && n > i)
                factors.push_back(i);
        vector<int> temp;
        
        help(result, factors, temp, 0, n);
        return result;
    }
    
};

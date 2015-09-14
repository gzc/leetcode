class Solution {
public:
    int numSquares(int n) {
        
        static vector<int> p {0};
        
        while(p.size() <= n)
        {
            int res = INT_MAX;
            for(int i = 1;i*i <= p.size();i++)
                res = min(res, p[p.size()-i*i]+1);
            p.push_back(res);
        }
        
        return p[n];
    }
};
class Solution {
    
    int help(vector<int> &prices)
    {
        int res(0);
        for(int i = 0;i < prices.size()-1;i++)
            if(prices[i+1] > prices[i])
                res += (prices[i+1] - prices[i]);
        return res;
    }
    
public:
    int maxProfit(int k, vector<int> &prices) {
        
        int len = prices.size();
        if(len < 2) return 0;
        if(k >= len/2) return help(prices);
    
        vector<vector<int> >p(k+1, vector<int>(len+1, 0));
        for(int i = 1;i <= k;i++)
        {
            int tmp = -prices[0];
            for(int j = 1;j <= len;j++)
            {
                p[i][j] = max(p[i][j-1], tmp+prices[j-1]);
                tmp = max(tmp, p[i-1][j-1] - prices[j-1]);
            }
        }
        
        return p[k][len];
    }
};

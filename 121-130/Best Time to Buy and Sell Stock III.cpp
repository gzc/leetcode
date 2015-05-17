class Solution {
    

    
public:
    int maxProfit(vector<int> &prices) {
        
        if(prices.size() < 2)
            return 0;
        int n = prices.size();
        vector<vector<int>> p (2, vector<int>(n,0));
        
        int minimum(INT_MAX),result(0);
        for(int i = 0;i < prices.size();i++)
        {
            minimum = min(minimum, prices[i]);
            result = max(result, prices[i]-minimum);
            p[0][i] = result;
        }
        int maximum = INT_MIN;
        result = 0;
        for(int i = n-1;i >= 0;i--)
        {
            maximum = max(maximum, prices[i]);
            result = max(result, maximum - prices[i]);
            p[1][i] = result;
        }
        
        
        int profit(0);
        for(int k = 0;k < n;k++)
        {
            if(k == n-1)
                profit = max(profit, p[0][k]);
            else
                profit = max(profit, p[0][k]+p[1][k+1]);
        }
        
        return profit;
        
    }
};

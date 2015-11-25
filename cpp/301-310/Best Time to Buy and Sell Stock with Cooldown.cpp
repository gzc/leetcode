class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n+1, INT_MIN);
        vector<int> sell(n+1, 0);
        vector<int> cold(n+1, 0);
        
        for(int i = 0;i < prices.size();i++)
        {
            buy[i+1] = max(cold[i] - prices[i], buy[i]);
            sell[i+1] = max(buy[i] + prices[i], sell[i]);
            cold[i+1] = max(max(buy[i],sell[i]), cold[i]);
        }
        
        return max(max(buy[n],sell[n]), cold[n]);
    }
};
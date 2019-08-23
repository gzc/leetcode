class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n+1, INT_MIN);
        vector<int> sell(n+1, 0);
        vector<int> cold(n+1, 0);
        
        for (int i = 0; i < prices.size(); i++) {
            buy[i+1] = max(cold[i] - prices[i], buy[i]);
            sell[i+1] = max(buy[i] + prices[i], sell[i]);
            cold[i+1] = max(max(buy[i], sell[i]), cold[i]);
        }
        
        return max(sell[n], cold[n]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int old_cooldown = cooldown;
            cooldown = max(cooldown, sell);
            sell = max(sell, buy + prices[i]);
            buy = max(buy, old_cooldown - prices[i]);
        }
        
        return max(sell, cooldown);
    }
};

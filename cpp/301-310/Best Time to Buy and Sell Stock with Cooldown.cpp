class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int old_cooldown = cooldown;
            cooldown = sell;
            sell = max(sell, buy + prices[i]);
            buy = max(buy, old_cooldown - prices[i]);
        }
        
        return max(sell, cooldown);
    }
};

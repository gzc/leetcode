class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int holdStock = -prices[0];
        int noStock = 0;

        for (int e : prices) {
            int tmpHoldStock = holdStock;
            holdStock = max(holdStock, noStock - e);
            noStock = max(noStock, tmpHoldStock + e - fee);
        }
        
        return noStock;
    }
};

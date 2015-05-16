class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        if(prices.size() < 2) return 0;
        
        int start(0), end(0), profit(0);
        while(end < prices.size() - 1)
        {
            while(start < prices.size() - 1 && prices[start+1] <= prices[start])
                ++start;
                
            if(start == prices.size()-1)
                    return profit;
            
            end = start+1;
            while(end < prices.size()-1 && prices[end+1] >= prices[end])
                ++end;
                
            profit += prices[end] - prices[start];
            start = end+1;
        }
        
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int minimum(INT_MAX),result(0);
        
        for(vector<int>::iterator it = prices.begin(); it != prices.end(); it++)
        {
            minimum = min(minimum, *it);
            result = max(result, *it-minimum);
            
        }
        return result;
    }
};

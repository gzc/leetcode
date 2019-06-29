class Solution {

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        bool dp[1501] = {false};
        dp[0] = true;
        for (int v : stones) {
            sum += v;
            for (int start = sum; start >= v; start--) {
                // we need to start from back to make it not affected by itself
                dp[start] = dp[start] | dp[start-v];
            }
        }
        
        for (int i = sum/2; i > 0; i--) {
            if (dp[i] == true) {
                return sum - 2 * i;
            }
        }
        return 0;
    }
};

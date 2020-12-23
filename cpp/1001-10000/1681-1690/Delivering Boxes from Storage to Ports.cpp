class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        int weight = 0;
        int trips = 2;
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            weight += boxes[right][1];
            
            // If current box is different than previous one, need to make one more trip.
            if (right > 0 && boxes[right][0] != boxes[right-1][0]) {
                trips++;   
            }
            
            while ((right - left) >= maxBoxes || weight > maxWeight || 
                  (left < right && dp[left] == dp[left+1])) {
                weight -= boxes[left][1];
                
                if (boxes[left][0] != boxes[left+1][0]) {
                    trips--;
                }
                
                left++;
            }
            
            dp[right+1] = dp[left] + trips;
        }
        
        return dp.back();
    }
};

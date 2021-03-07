class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(k, vector<int>(1025, 0));
        for (int i = 0; i < n; i++) {
            freq[i%k][nums[i]]++;
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(1025, 2001));
        dp[0][0] = 0;
        
        for (int i = 0; i < k; i++) {
            int total = (n + k - i - 1) / k;
            int previous_minimum_changes = *min_element(dp[i].begin(), dp[i].end());
            
            for (int target = 0; target <= 1024; target++) {
                dp[i+1][target] = total + previous_minimum_changes;
                
                for (int index = i; index < n; index += k) {
                    int picked = nums[index];
                    int previous_target = picked ^ target;
                    if (previous_target > 1024) {
                        continue;
                    }
                    dp[i+1][target] = min(dp[i+1][target],
                                          dp[i][previous_target] + total - freq[i][picked]);
                }
            }
        }
        
        return dp[k][0];
    }
};

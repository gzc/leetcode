class Solution {
    
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        sum /= 2;
        
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        sort(nums.begin(), nums.end());
        
        for (int num : nums)
            for (int i = 0;i <= sum-num;i++)
                if (dp[i] == true) dp[i + num] = true;
                
        return dp[sum];
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), maxCnt=0, maxLen=0;
        vector<int> dp(n,1), cnt(n,1);
        for(int i=0; i<n; ++i){
            for(int j =0; j<i; ++j)
                if (nums[i] > nums[j]) {
                    if(dp[j] + 1 == dp[i]) 
                        cnt[i] += cnt[j];
                    else if(dp[j] + 1 > dp[i]){
                        dp[i] =  dp[j] + 1;
                        cnt[i] = cnt[j];
                    }                   
                }           
            maxLen = max(maxLen, dp[i]);
	    }
        for(int i=0; i<n; ++i)  {
            if(dp[i] == maxLen)  
                maxCnt += cnt[i];
        }
        
        return maxCnt;     
    }
};

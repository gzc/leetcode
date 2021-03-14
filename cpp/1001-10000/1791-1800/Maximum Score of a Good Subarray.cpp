class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int mini = nums[k];
        int ans = mini;
        
        int i = k;
        int j = k;
        
        while (i > 0 || j < nums.size() - 1) {
            if (i == 0 || (j+1 < nums.size() && nums[i-1] <= nums[j+1])) {
                j++;
                mini = min(mini, nums[j]);
                ans = max(ans, mini * (j - i + 1));
            } else {
                i--;
                mini = min(mini, nums[i]);
                ans = max(ans, mini * (j - i + 1));
            }
        }
        
        return ans;
    }
};

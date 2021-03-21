class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            ans = max(ans, cur);
        }
        
        return ans;
    }
};

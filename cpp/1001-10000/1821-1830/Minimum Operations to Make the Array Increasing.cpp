class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            int previous = nums[i-1];
            int current = nums[i];
            
            if (current <= previous) {
                current = previous + 1;
                ans += (current - nums[i]);
                nums[i] = current;
            }
        }
        
        return ans;
    }
};

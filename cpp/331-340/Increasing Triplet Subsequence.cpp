class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int min1(INT_MAX), min2(INT_MAX);
        
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] > min2) return true;
            if(nums[i] > min1) min2 = min(min2, nums[i]);
            else min1 = nums[i];
        }
        
        return false;
        
    }
};
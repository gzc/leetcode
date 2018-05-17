class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minimum = INT_MAX;
        int lastBadIndex = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            minimum = min(minimum, nums[i]);
            if (minimum != nums[i]) lastBadIndex = i;
        }
        
        int maximum = INT_MIN;
        int lastBadIndex2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            maximum = max(maximum, nums[i]);
            if (maximum != nums[i]) lastBadIndex2 = i;
        }
        if (lastBadIndex2 <= lastBadIndex) return 0;
        return lastBadIndex2 - lastBadIndex + 1;
    }
};

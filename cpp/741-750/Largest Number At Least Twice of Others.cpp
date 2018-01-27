class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxOne = 0, maxTwo = 0, idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxOne < nums[i]) {
                maxTwo = maxOne;
                maxOne = nums[i];
                idx = i;
            } else if (maxTwo < nums[i]) {
                maxTwo = nums[i];
            }
        }
        return maxOne >= maxTwo * 2 ? idx : -1;
    }
};

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int temp1 = 0;
        for (int i = 1; i < nums.size(); i += 2) {
            int ele = nums[i-1];
            if (i+1 < nums.size()) ele = min(ele, nums[i+1]);
            if (nums[i] >= ele) {
                temp1 += (nums[i] - ele + 1);
            }
        }
        
        int temp2 = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int ele = min(i-1 >= 0 ? nums[i-1] : 10000, i+1 < nums.size() ? nums[i+1] : 10000);
            if (nums[i] >= ele) {
                temp2 += (nums[i] - ele + 1);
            }
        }
        
        return min(temp1, temp2);
    }
};

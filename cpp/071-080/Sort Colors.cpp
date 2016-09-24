class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                swap(nums[j], nums[r]);
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[r] == 1) {
                swap(nums[r], nums[j]);
                j++;
            }
        }
    }
};

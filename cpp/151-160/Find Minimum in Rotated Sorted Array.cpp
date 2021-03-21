class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] < nums[j]) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        
        return nums[i];
    }
};

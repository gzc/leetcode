class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[i]) {
                if (nums[mid] < target && nums[j] >= target) i = mid+1;
                else j = mid-1;
            } else {
                if (nums[mid] > target && nums[i] <= target) j = mid-1;
                else i = mid+1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] < nums[i]) {
                if (nums[mid] < target && nums[j] >= target) i = mid + 1;
                else j = mid - 1;
            } else if (nums[mid] > nums[i]) {
                if (nums[mid] > target && nums[i] <= target) j = mid - 1;
                else i = mid + 1;
            } else {
                i++;
            }
        }
        
        return false;
    }
};

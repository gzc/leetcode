class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid-1]) right = mid - 2;
                else if (nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            } else {
                if (nums[mid] == nums[mid-1]) left = mid + 1;
                else if (nums[mid] == nums[mid+1]) right = mid - 1;
            }
        }
        return nums[left];
    }
};

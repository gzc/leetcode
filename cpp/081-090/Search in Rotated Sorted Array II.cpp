class Solution {
public:
    bool search(vector<int>& nums, int key) {
        int l(0), r(nums.size() - 1);
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == key) return true;
            if (nums[l] < nums[m]) {
                if (nums[l] <= key && key < nums[m]) r = m - 1;
                else l = m + 1;
            } else if (nums[l] > nums[m]) {
                if (nums[m] < key && key <= nums[r]) l = m + 1;
                else r = m - 1;
            } else l++;
        }
        return false;
    }
};

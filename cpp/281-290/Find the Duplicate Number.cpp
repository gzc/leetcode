class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left(1), right(n);
        while (left < right) {
            int mid = (left+right)/2;
            int less(0), duplicate(0);
            for (int i = 0;i < n;i++) {
                if (nums[i] < mid) less++;
                else if(nums[i] == mid) duplicate++;
            }
            if (duplicate > 1) return mid;
            less > mid - 1 ? right = mid - 1 : left = mid + 1;
        }
        return left;
    }
};

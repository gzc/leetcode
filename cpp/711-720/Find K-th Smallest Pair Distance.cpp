class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) return INT_MIN;
        sort (nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = nums[n-1] - nums[0];
        while (low < high) {
            int mid = low + (high-low) / 2;
            int left = 0;
            int right = 1;
            int cnt = 0;
            while (right < n) {
                if (nums[right] - nums[left] > mid) {
                    ++left;
                } else {
                    cnt += (right-left);
                    ++right;
                }
            }
            if (cnt < k) low = mid+1;
            else high = mid;
        }
        return low;
    }
};

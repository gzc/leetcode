class Solution {
    int binarySearch(const vector<int>& nums, int mid) {
        int lessThanMid = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto it = std::upper_bound (begin(nums), end(nums), mid + nums[i]);
            lessThanMid += (it - (nums.begin())) - i - 1;
        }
        return lessThanMid;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int high = nums[n-1] - nums[0];
        int low = 0;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int lessThanMid = binarySearch(nums, mid);
            if (lessThanMid < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};

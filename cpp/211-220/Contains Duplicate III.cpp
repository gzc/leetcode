class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // -t <= x - nums[i] <= t;
            auto pos = window.lower_bound((long)nums[i] - (long)t); // x >= nums[i] - t
            if (pos != window.end() && *pos - nums[i] <= t) // x <= nums[i] + t
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

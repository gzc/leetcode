class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int mod = 1e9 + 7;
        int res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            res += abs(nums1[i] - nums2[i]);
            res %= mod;
        }
        
        int minus = 0;
        vector<int> copy_nums = nums1;
        sort(copy_nums.begin(), copy_nums.end());
        for (int i = 0; i < nums1.size(); i++) {
            int original = abs(nums1[i] - nums2[i]);
            int dis = 0;
            auto it = lower_bound(copy_nums.begin(), copy_nums.end(), nums2[i]);
            if (it == copy_nums.end()) {
                it--;
                dis = abs(*it - nums2[i]);
            } else {
                dis = abs(*it - nums2[i]);
                if (it != copy_nums.begin()) {
                    it--;
                    dis = min(dis, abs(*it - nums2[i]));
                }
            }
            
            minus = max(minus, original - dis);
        }
        
        res -= minus;
        if (res < 0) res += mod;
        
        return res;
    }
};

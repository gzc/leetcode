class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            sums.push_back(sum);
        }
        
        long ans = 0;
        long mod = 1e9+7;
        int sum_left = 0;
        for (int left = 0; left < n; left++) {
            sum_left += nums[left];
            
            auto it1 = lower_bound(sums.begin()+left+1, sums.end(), 2*sum_left);
            if (it1 == sums.end()) break;
            
            int target = (sum - sum_left )/2 + sum_left;
            // 0 0 0 0 0 0 1
            auto it2 = lower_bound(it1, sums.end(), target);
            if (it2 == sums.end()) break;
            auto it3 = upper_bound(it1, sums.end(), target);
            if (it3 == sums.end()) {
                it3--;
            }
            it3--;
            
            ans += (it3 - it1 + 1);
            ans = ans % mod;
        }
        
        return ans % mod;
    }
};

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
        int j = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            sum_left += nums[i];
            
            if (sum_left*3 > sum) break;
            
            j = max(j, i+1);
            while (j < n-1 && ((sums[j] - sums[i]) < sum_left)) j++;
            
            int sum_remain = sum - sum_left;
            k = max(k, j);
            while (k < n-1) {
                int l = sums[k] - sums[i];
                int r = sum_remain - l;
                if (l > r) {
                    break;
                }
                else k++;
            }
            
            ans += (k - j);
            
        }
        
        return ans % mod;
    }
};


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
            auto it2 = upper_bound(it1, --sums.end(), target);
            if (it2 == sums.end()) break;
            
            ans += (it2 - it1);
        }
        
        return ans % mod;
    }
};

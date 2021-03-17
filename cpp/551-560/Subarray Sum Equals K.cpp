class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        
        int sum = 0;
        int ans = 0;
        for (int num : nums) {
            sum += num;
            int target = sum - k;
            ans += prefix_sum[target];
            prefix_sum[sum]++;
        }
        
        return ans;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double res = sum/k;
        for (int i = 0; i < nums.size() - k; i++) {
            sum = sum - nums[i] + nums[i+k];
            res = max(res, sum/k);
        }
        return res;
    }
};

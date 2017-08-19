class Solution {
    bool validate(const vector<int>& nums, int k, double mid) {
        vector<double> numsCopy(nums.size());
        for (int i = 0; i < nums.size(); i++) numsCopy[i] = nums[i] - mid;
        double sum = 0;
        double prevSum = 0;
        double minPrevSum = 0;
        for (int i = 0; i < numsCopy.size(); i++) {
            sum += numsCopy[i];
            if (i >= k) {
                prevSum += numsCopy[i - k];
                minPrevSum = min(minPrevSum, prevSum);
                if (sum > minPrevSum) return true;
            }
            if (i == k - 1) {
                if (sum >= 0) return true;
            }
        }
        return false;
    }
    
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto result = std::minmax_element(nums.begin(), nums.end());
        double left = *result.first;
        double right = *result.second;
        
        while (abs(right - left) > 1e-5) {
            double mid = (left + right) / 2;
            if (validate(nums, k, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};

class Solution {
    
    long getSumInRange(long peak, int length) {
        long sum = 0;
        if (length > peak) {
            sum += (1 + peak) * peak / 2;
            sum += (length - peak);
        } else {
            long minimum = peak - length + 1;
            sum += (minimum + peak) * length / 2;
        }
        return sum;
    }
    
    bool check(int n, int index, int maxSum, int peak) {
        long sum = getSumInRange(peak, index + 1) + getSumInRange(peak, n - index) - peak;
        return sum > (long)maxSum;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1;
        int right = maxSum;
        int ans = 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            bool exceed = check(n, index, maxSum, mid);
            if (exceed) {
                right = mid - 1;
            } else {
                ans = mid;
                left = mid + 1;
            }
        }
        
        return ans;
    }
};

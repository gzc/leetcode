class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
        for (int a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum >= 0 ? max(maxSum, total - minSum) : maxSum;
    }
};

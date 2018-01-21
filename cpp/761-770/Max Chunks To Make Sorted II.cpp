class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n, arr[0]);
        vector<int> rightMin(n, arr[n-1]);
        
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i+1], arr[i]);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                result++;
            } else if (rightMin[i + 1] >= leftMax[i]) {
                result++;
            }
        }
        
        return result;
    }
};

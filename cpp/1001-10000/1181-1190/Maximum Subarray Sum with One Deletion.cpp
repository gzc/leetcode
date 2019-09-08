class Solution {
    
    int getV(vector<int>& dp, int i) {
        if (i < 0 || i >= dp.size()) return -100000;
        return dp[i];
    }
    
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0); 

        dp1[0] = arr[0]; 
        for (int i = 1; i < n; i++)  { 
            dp1[i] = max(arr[i], dp1[i-1] + arr[i]); 
        }

        dp2[n-1] = arr[n-1]; 
        for (int i = n-2; i >= 0; i--)  { 
            dp2[i] = max(arr[i], dp2[i+1] + arr[i]);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, max(getV(dp1, i-1), getV(dp2, i+1)));
            ans = max(ans, getV(dp1, i-1) + getV(dp2, i+1));
        }
        return ans; 
    }
};

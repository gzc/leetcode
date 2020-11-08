class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> ans(n+1, 0);
        int val = 0;
        for (int i = 0; i <= n; i++) {
            if (i == 0) ans[i] = 0;
            else if (i == 1) ans[i] = 1;
            else if (i % 2 == 0) ans[i] = ans[i/2];
            else ans[i] = ans[i/2] + ans[i/2+1];
            val = max(val, ans[i]);
        }
        return val;
    }
};

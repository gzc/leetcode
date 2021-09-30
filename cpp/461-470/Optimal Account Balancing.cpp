class Solution {
    
    int helper(vector<int>& a, int start, int n) {
        int ans = INT_MAX;
        while(start < n && a[start] == 0) start++;
        for (int i = start + 1; i < n; ++i) {
            if ( (a[i] * a[start] < 0) ) {
                a[i] += a[start];
                ans = min(ans, 1 + helper(a, start + 1, n));
                a[i] -= a[start];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        map<int, int> net;
        for (const auto& t : transactions) {
            net[t[0]] -= t[2];
            net[t[1]] += t[2];
        }
        vector<int> a;
        for (const auto& ele : net) {
            if (ele.second != 0) {
                a.push_back(ele.second);
            }
        }
        
        return helper(a, 0, a.size());
    }
};

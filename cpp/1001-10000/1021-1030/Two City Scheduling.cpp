class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), [](vector<int> &v1, vector<int> &v2) {
            return abs(v1[0] - v1[1]) > abs(v2[0] - v2[1]);
        });
      
        int a = costs.size()/2;
        int b = costs.size()/2;
        
        int ans = 0;
        
        for (const vector<int>& cost : costs) {
            if (a == 0) {
                ans += cost[1];
                continue;
            }
            if (b == 0) {
                ans += cost[0];
                continue;
            }
            if (cost[0] <= cost[1]) {
                ans += cost[0];
                a--;
            } else {
                ans += cost[1];
                b--;
            }
        }
        
        return ans;
    }
};

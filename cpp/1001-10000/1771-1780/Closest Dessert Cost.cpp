class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        bool table[20010] = {false};
        int ans = -999999;
        for (int base : baseCosts) {
            table[base] = true;
        }
        
        for (int cost : toppingCosts) {
            for (int k = 1; k <= 2; k++) {
                for (int v = 20000; v >= 0; v--) {
                    if (v - cost >= 0 && table[v - cost] == true) {
                        table[v] = true;
                    }
                }
            }
        }
        
        for (int i = 1; i <= 20001; i++) {
            if (table[i] == true && abs(i - target) < abs(ans - target)) {
                ans = i;
            }
        }
        
        return ans;
    }
};

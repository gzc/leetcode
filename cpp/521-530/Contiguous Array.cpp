class Solution {
    
    int get(int v) {
        return v == 1 ? 1 : -1;
    }
    
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        map<int, int> mymap;
        mymap[0] = -1;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) dp[0] = get(nums[i]);
            else dp[i] = dp[i - 1] + get(nums[i]);
            auto itt = mymap.find(dp[i]);
            if (itt != mymap.end()) {
                result = max(result, i - itt->second);
            } else {
                mymap[dp[i]] = i;
            }
        }
        
        return result;
    }
};

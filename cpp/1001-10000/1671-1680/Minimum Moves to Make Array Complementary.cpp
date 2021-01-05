class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2*limit+2, 0);
        
        for (int i = 0; i < n/2; i++) {
            int a = min(nums[i], nums[n-1-i]);
            int b = max(nums[i], nums[n-1-i]);
            delta[2] += 2;
            delta[a + 1]--;
            delta[a + b]--;
            delta[a + b + 1]++;
            delta[b + limit + 1]++;
        }
        
        int res = 2 * n;
        int curr = 0;
        for (int i = 2; i <= 2 * limit; i++) {
            curr += delta[i];
            res = min(res, curr);
        }
        return res;
    }
};

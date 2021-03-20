class Solution {
    int dfs(const vector<int>& nums, int round, int state, unordered_map<int, int>& cache) {
        if (round > nums.size() / 2) {
            return 0;
        }
        if (cache.count(state) > 0) {
            return cache[state];
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int picked = (1 << i) | (1 << j);
                if ((state & picked) == 0) {
                    ans = max(ans, round * __gcd(nums[i], nums[j]) + dfs(nums, round + 1, state | picked, cache));
                }
            }
        }

        return cache[state] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        unordered_map<int, int> cache;
        return dfs(nums, /*round=*/1, /*state=*/0, cache);
    }
};


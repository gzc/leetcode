class Solution {
    
    int dfs(const vector<int>& nums, int i, int S, map<pair<int, int>, int>& cache) {
        pair<int, int> key = {i, S};
        if (cache.count(key) > 0) return cache[key];
        
        if (i == nums.size())
            return S == 0 ? 1 : 0;
            
        int curNum = nums[i];
        int v1 = dfs(nums, i + 1, S - curNum, cache);
        int v2 = dfs(nums, i + 1, S + curNum, cache);
        return cache[key] = v1+v2;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        map<pair<int, int>, int> cache;
        return dfs(nums, 0, S, cache);
    }
};

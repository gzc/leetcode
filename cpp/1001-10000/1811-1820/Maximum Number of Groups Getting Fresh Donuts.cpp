class Solution {
public:
    string GetKey(const vector<int>& cnts) {
        stringstream ss;
        for (int i = 1; i < cnts.size(); i++) {
            ss << i << ":" << cnts[i] << ":";
        }
        return ss.str();
    }
    
    int dfs(vector<int>& cnts, int remain, int batchSize, unordered_map<string, int>& cache) {
        string key = GetKey(cnts);
        if (cache.count(key) > 0) {
            return cache[key];
        }
        
        int res = 0;
        for (int i = 1; i < cnts.size(); i++) {
            if (cnts[i] == 0) continue;
            
            int tmp = (remain == 0 ? 1 : 0);
            cnts[i]--;
            tmp += dfs(cnts, (remain - i + batchSize) % batchSize, batchSize, cache);
            cnts[i]++;
            res = max(res, tmp);
        }
        return cache[key] = res;
    }
    
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        int res = 0;
        vector<int> cnts(batchSize, 0);
        for (int group : groups) {
            int g = group % batchSize;
            if (g == 0) {
                res++;
            } else if (cnts[batchSize - g] > 0) {
                res++;
                cnts[batchSize - g]--;
            } else {
                cnts[g]++;
            }
        }
        
        // batchSize = 4, groups = [1,3,2,5,2,2,1,6]
        // cnts = [0, 3, 4, 1] -> [0, 2, 0, 0] res = 3
        unordered_map<string, int> cache;
        return res + dfs(cnts, /*remain=*/0, batchSize, cache);
    }
};

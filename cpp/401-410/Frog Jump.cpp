class Solution {
    
    bool dfs(const vector<int>& stones, int stone_index, int speed, unordered_map<int, bool>& cache) {
        if (stone_index == stones.size() - 1) return true;
        
        int key = (stone_index) | (speed << 12);
        if (cache.count(key) > 0) {
            return cache[key];
        }
        
        for (int i = stone_index + 1; i < stones.size(); i++) {
            int distance = stones[i] - stones[stone_index];
            if (distance >= (speed - 1) && distance <= (speed + 1)) {
                if (dfs(stones, i, distance, cache)) {
                    return cache[key] = true;
                }
            }
        }
        return cache[key] = false;
    }
    
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> cache;
        return dfs(stones, 0, 0, cache);
    }
};

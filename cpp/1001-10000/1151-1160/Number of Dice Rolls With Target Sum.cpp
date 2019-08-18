class Solution {
    unordered_map<int, long> cache;
public:
    int numRollsToTarget(int d, int f, int target) {
        if (target == 0) {
            if (d == 0) return 1;
            return 0;
        }
        if (d <= 0 || target <= 0) return 0;
        int key = d * 1001 + target;
        if (cache.count(key) > 0) return cache[key];
        
        long res = 0;
        for (int i = 1; i <= f; i++) {
            res = (res + (long)numRollsToTarget(d-1, f, target - i)) % 1000000007L;
        }
        
        return cache[key] = res;
    }
};

class Solution {
    
    int buildkey (bool *nums, int N) {
        int key = 0;
        for (int i = 1; i <= N;i++) if (nums[i] == true) key |= (1 << i);
        return key;
    }
    
    bool caniwin (bool *nums, int N, int desiredTotal, map<int, bool> &cache) {
        
        int key = buildkey(nums, N);
        
        if (cache.count(key) > 0) return cache[key];
        
        for (int i = 1; i <= N; i++) {
            
            if (nums[i] == false) {
                
                if (i >= desiredTotal) return true;
                
                nums[i] = true;
                bool win = !caniwin(nums, N, desiredTotal - i, cache);
                nums[i] = false;
                
                if (win) return cache[key] = true;
            }
        }
        
        return cache[key] = false;
    }
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        if (desiredTotal == 0) return true;
        
        if ( (1 + maxChoosableInteger) * maxChoosableInteger / 2  < desiredTotal) return false;
        
        bool nums[maxChoosableInteger+1] = {false};
        
        map<int, bool>cache;
        
        return caniwin(nums, maxChoosableInteger, desiredTotal, cache);
        
    }
};

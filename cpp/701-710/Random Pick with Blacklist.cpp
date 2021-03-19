class Solution {
    random_device rd;
    unordered_map<int, int> updated_index;
    int mod;
public:
    Solution(int N, vector<int>& blacklist) {
        mod = N - blacklist.size();
        set<int> blacklist_set(blacklist.begin(), blacklist.end());
        
        int swap_num = N - 1;
        for (int blick_element : blacklist_set) {
            while (blacklist_set.count(swap_num) > 0) {
                swap_num--;
            }
            
            if (blick_element > swap_num) break;
            
            updated_index[blick_element] = swap_num;
            swap_num--;
        }
    }
    
    int pick() {
        int index = rd() % mod;
        if (updated_index.count(index) > 0) {
            return updated_index[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

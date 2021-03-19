// Solution 1: Binary Search. O(log)
class Solution {
    vector<int> v;
    std::random_device rd;
    int mod;
public:
    Solution(int N, vector<int> blacklist) {
        mod = N - blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        v = blacklist;
        v.push_back(N);
        for (int i = 0; i < v.size(); i++) v[i] -= i;
    }
    
    int pick() {
        int index = rd() % mod;
        auto it = upper_bound(v.begin(), v.end(), index);
        return index + (it - v.begin());
    }
};

// Solution 2: hash_map; O(1)
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
            if (blick_element >= mod) break;
            while (blacklist_set.count(swap_num) > 0) {
                swap_num--;
            }
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

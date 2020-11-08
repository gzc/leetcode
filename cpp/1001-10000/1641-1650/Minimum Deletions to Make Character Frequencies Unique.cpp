class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mymap;
        for (char ch : s) {
            mymap[ch]++;
        }
        
        set<int> used;
        
        int ans = 0;
        
        for (const auto& it : mymap) {
            int freq = it.second;
            while(used.count(freq) > 0) {
                freq--;
                ans++;
            }
            if (freq > 0) {
                used.insert(freq);
            }
        }
        
        return ans;
    }
};

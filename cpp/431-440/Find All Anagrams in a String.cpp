class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mymap;
        int psize = p.size();
        vector<int> ans;
        
        for (char ch : p) mymap[ch]++;
        int cnt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            mymap[ch]--;
            
            if (mymap[ch] >= 0) cnt++;
            
            if (i >= psize) {
                char poped_ch = s[i - psize];
                int times = ++mymap[poped_ch];
                if (times > 0) cnt--;
            }
            
            if (cnt == psize) ans.push_back(i - psize + 1);
        }
        
        return ans;
    }
};

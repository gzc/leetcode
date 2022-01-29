class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mymap;
        int start = 0;
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            auto it = mymap.find(ch);
            if (it != mymap.end()) {
                start = max(start, it->second + 1);
            }
            
            mymap[ch] = i;
            ans = max(ans, i - start + 1);
        }
        
        return ans;
    }
};

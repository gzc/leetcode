class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int longest = 0;
        int previouspos = 0;
        unordered_map<char, int>m;
        
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            if (m[s[i]] == 1) {
                cnt++;
            }

            while (cnt > k) {
                char ch = s[previouspos];
                previouspos++;
                m[ch]--;
                if(m[ch] == 0) {
                    cnt--;
                }
            }
            
            longest = max(longest, i-previouspos+1);
        }
        
        return longest;
    }
};

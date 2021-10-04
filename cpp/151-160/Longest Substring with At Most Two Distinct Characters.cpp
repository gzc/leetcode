class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int current = 0;
        int longest = 0;
        int previouspos = 0;
        unordered_map<char, int> m;
        
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            if (m[s[i]] == 1) {
                current++;
            }

            while (current > 2) {
                char ch = s[previouspos];
                previouspos++;
                m[ch]--;
                if (m[ch] == 0) {
                    current--;
                }
            }
            
            longest = max(longest, i - previouspos + 1);
        }
        
        return longest;
    }
};

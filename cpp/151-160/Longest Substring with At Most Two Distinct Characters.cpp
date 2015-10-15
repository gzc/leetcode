class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int current(0);
        int longest(INT_MIN);
        int previouspos(0);
        map<char, int>m;
        
        for(int i = 0;i < s.length();i++)
        {
            if(current < 2 && m[s[i]] == 0) {
                m[s[i]] = 1;
                current++;
            } else if(current < 2) {
                m[s[i]]++;
            } else {
                if(m[s[i]] > 0) {
                    m[s[i]]++;
                } else {
                    longest = max(longest, i-previouspos);
                    m[s[i]] = 1;
                    while(1) {
                        char ch = s[previouspos];
                        previouspos++;
                        m[ch]--;
                        if(m[ch] == 0) {
                            break;
                        }
                    }
                }
            }
        }
        longest = max(longest, (int)s.length()-previouspos);
        return longest;
    }
};
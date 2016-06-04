class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool p[256] = {false};
        int result(0),k(0);
        
        for(int i = 0;i < s.length();i++) {
            char ch = s[i];
            if(!p[ch]) {
                p[ch] = true;
                result = max(result, i-k+1);
            } else {
                while(1) {
                    if(s[k] == ch) {
                        k++;
                        break;
                    }
                    p[s[k++]] = false;
                }
            }
        }
        
        return result;
    }
};

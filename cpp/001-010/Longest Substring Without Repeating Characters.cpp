class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool visited[256] = {false};
        int result(0), k(0);
        
        for (int i = 0;i < s.length();i++) {
            char ch = s[i];
            if (visited[ch] == false) {
                visited[ch] = true;
                result = max(result, i-k+1);
            } else {
                while (true) {
                    if (s[k] == ch) {
                        k++;
                        break;
                    }
                    visited[s[k++]] = false;
                }
            }
        }
        
        return result;
    }
};

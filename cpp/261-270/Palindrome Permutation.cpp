class Solution {
public:
    bool canPermutePalindrome(string s) {
        int ch[128] = {0};
        for (int i = 0;i < s.length();i++) 
            ch[s[i]]++;
        
        int odd(0), even(0);
        for (int i = 0;i < 256;i++) {
            if (ch[i] > 0) {
                ch[i] % 2 == 1 ? odd++ : even++;
            }
        }
        
        if (odd >= 2) return false;
        if (odd == 1) {
            if (s.length() % 2 == 1) return true;
            return false;
        }
        return true;
    }
};

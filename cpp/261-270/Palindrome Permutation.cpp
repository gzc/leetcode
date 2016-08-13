class Solution {
    
public:
    bool canPermutePalindrome(string s) {
        int MAGIC(128);
        int ch[MAGIC] = {0};
        for (int i = 0;i < s.length();i++) 
            ch[s[i]]++;
        
        int odd(0), even(0);
        for (int i = 0;i < MAGIC;i++)
            if (ch[i] > 0)
                ch[i] % 2 == 1 ? odd++ : even++;
        
        if (odd >= 2) return false;
        else if (odd == 1) {
            if (s.length() % 2 == 1) return true;
            return false;
        }
        else return true;
    }
};

class Solution {
    
public:
    bool isOneEditDistance(string s, string t) {
        if (abs((int)s.length() - (int)t.length()) >= 2) return false;
        if (s == t) return false;
        if (s.length() == t.length()) {
            int diff(0);
            for (int i = 0;i < s.length();i++)
            {
                if (s[i] != t[i]) diff++;
                if (diff >= 2) return false;
            }
            return true;
        }
        if (s.length() > t.length()) return isOneEditDistance(t, s);
        
        int i(0), j(0);
        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j]){
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == s.length() && j == t.length()) return true;
        if (j == i) return true;
        return false;
    }
    
};

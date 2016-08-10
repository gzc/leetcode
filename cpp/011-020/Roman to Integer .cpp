class Solution {
public:
    
    int romanToInt(string s) {
        
        map<char, int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int r(0);
        for (int i = 0;i < s.length();i++)
        {
            if (i < s.length()-1 && m[s[i]] < m[s[i+1]] ) r -= m[s[i]];
            else r += m[s[i]];
        }
        
        return r;
    }
    
};

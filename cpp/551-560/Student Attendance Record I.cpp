class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int A = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'A') A++;
            if (ch == 'L' && (i+1 < n && s[i+1] == 'L') && (i+2<n && s[i+2] == 'L')) return false; 
        }
        if (A <= 1) return true;
        return false;
    }
};

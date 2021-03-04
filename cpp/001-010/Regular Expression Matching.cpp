class Solution {
    
    bool isMatch(const string& s, int sidx, const string& p, int pidx) {
        if (pidx >= p.length()) {
            return sidx == s.length();
        }
        if ((pidx + 1) < p.length() && p[pidx + 1] == '*') {
            if (isMatch(s, sidx, p, pidx + 2)) {
                return true;
            }
            if (sidx < s.length() && (p[pidx] == '.' || s[sidx] == p[pidx])) {
                return isMatch(s, sidx + 1, p, pidx);
            }
        } else if (sidx < s.length() && (p[pidx] == '.' || s[sidx] == p[pidx])) {
            return isMatch(s, sidx + 1, p, pidx + 1);
        }
        return false;
    }
    
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (idx1 == -1) {
                    idx1 = i;
                } else if (idx2 == -1) {
                    idx2 = i;
                } else {
                    return false;
                }
            }
        }
        
        if (idx1 < 0 && idx2 < 0) return true;
        if (idx2 < 0) return false;
        if (s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]) return true;
        return false;
    }
};

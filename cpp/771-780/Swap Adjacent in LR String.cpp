class Solution {
public:
    bool canTransform(string start, string end) {
        string s, t;
        
        for (char ch : start) {
            if (ch != 'X') {
                s += ch;   
            }
        }
        for (char ch : end) {
            if (ch != 'X') {
                t += ch;   
            }
        }
        if (s != t) return false;
        
        int sR = 0, sL = 0, eR = 0, eL = 0;
        for (int i = 0; i < start.length(); i++) {
            if (start[i] == 'L') sL++;
            if (start[i] == 'R') sR++;
            if (end[i] == 'R') eR++;
            if (end[i] == 'L') eL++;

            if (eR > sR) return false;
            if (sL > eL) return false;
        }
        
        return true;
    }
};

class Solution {
    
    int len;
    string ss;
    
    bool help() {
        for (int is = 0; is <= len-2; ++is) {
            if (ss[is] == '+' && ss[is+1] == '+') {
                ss[is] = ss[is+1] = '-';
                bool wins = !help();
                ss[is] = ss[is+1] = '+';
                if (wins) return true;
            }
        }
        return false;
    }
    
public:
    
    bool canWin(string s) {
        len = s.size();
        ss = s;
        return help();
    }
    
};
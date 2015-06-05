class Solution {
public:
    int titleToNumber(string s) {
        return s.length() == 0 ? 0 : (s.back() - 'A' + 1 ) + 26*titleToNumber(s.substr(0,s.length()-1));
    }
};

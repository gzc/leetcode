class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        for (int i = 1;i < s.length();i++) {
            if (s[i-1] == '+' && s[i] == '+') {
                s[i-1] = s[i] = '-';
                result.push_back(s);
                s[i-1] = s[i] = '+';
            }
        }
        return result;
    }
};

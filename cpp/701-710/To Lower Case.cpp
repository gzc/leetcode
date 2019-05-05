class Solution {
public:
    string toLowerCase(string str) {
        int d = 'A' - 'a';
        for (char& ch : str) {
            if (ch >= 'A' && ch <= 'Z') {
                ch -= d;
            }
        }
        return str;
    }
};

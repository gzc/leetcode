class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int l = B.length() / A.length();
        string temp;
        for (int i = 0; i < l; i++) temp += A;
        if (temp.find(B) != string::npos) {
            return l;
        }
        temp += A;
        if (temp.find(B) != string::npos) {
            return l+1;
        }
        temp += A;
        if (temp.find(B) != string::npos) {
            return l+2;
        }
        return -1;
    }
};

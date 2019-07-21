class Solution {

public:
    string strWithout3a3b(int A, int B) {
        string ans = " ";
        while (A > 0 || B > 0) {
            if (A == B) {
                A--;
                B--;
                ans = ans + (ans.back() == 'a' ? "ba" : "ab"); 
            } else if (A > B) {
                if (ans.back() == 'a') {
                    ans = ans + 'b';
                    B--;
                } else {
                    ans = ans + 'a';
                    A--;
                    if (A > 0) {
                        ans = ans + 'a';
                        A--;
                    }
                }
            } else {
                if (ans.back() == 'b') {
                    ans = ans + 'a';
                    A--;
                } else {
                    ans = ans + 'b';
                    B--;
                    if (B > 0) {
                        ans = ans + 'b';
                        B--;
                    }
                }
            }
        }
        return ans.substr(1);
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.length();
        for (int i = 1; i <= len/2; i++) {
            if (len % i != 0) continue;
            string part = str.substr(0, i);
            int dups = len / i;
            bool ff = true;
            for (int k = 0; k < dups; k++) {
                int idx = k * i;
                bool f = true;
                for (int j = 0; j < i; j++) {
                    if (str[idx + j] != str[j]) {
                        f = false;
                        break;
                    }
                }
                if (f == false) { ff = false; break; }
            }
            if (ff == false) continue;
            return true;
        }
        return false;
    }
};

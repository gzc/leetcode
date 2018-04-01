class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        int ls = S.length();
        for (const string& word : words) {
            int i(0), j(0);
            int lw = word.length();
            bool ok = true;
            while (i < ls && j < lw) {
                if (S[i] != word[j]) {
                    ok = false;
                    break;
                }
                int numS = 1, numW = 1;
                while (i+1 < ls && S[i] == S[i+1]) {
                    numS++;
                    i++;
                }
                while (j+1 < lw && word[j] == word[j+1]) {
                    numW++;
                    j++;
                }
                if (numS < numW) {
                    ok = false;
                    break;
                }
                if (numS > numW && numS < 3) {
                    ok = false;
                    break;
                }
                i++;
                j++;
            }
            if (ok && i == ls && j == lw) ans++;
        }
        return ans;
    }
};

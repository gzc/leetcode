class Solution {
public:
    int countLetters(string S) {
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < S.length()) {
            while (S[j] == S[i]) {
                j++;
            }
            int num = j - i;
            ans += ((1+num) * num / 2);
            i = j;
        }
        return ans;
    }
};

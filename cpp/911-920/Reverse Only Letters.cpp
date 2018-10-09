class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.length() - 1;
        while (i < j) {
            while (!isalpha(S[i])) i++;
            while (!isalpha(S[j])) j--;
            if (i < j) swap(S[i], S[j]);
            i++;
            j--;
        }
        return S;
    }
};

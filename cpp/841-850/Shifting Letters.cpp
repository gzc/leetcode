class Solution {
    
    char convert(char c, int x) {
        return (((c-'a')+x)%26) + 'a';
    }
    
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size() - 1; i >= 1; i--) {
            shifts[i-1] += (shifts[i]%26);
        }
        for (int i = 0; i < S.length(); i++) {
            S[i] = convert(S[i], shifts[i]);
        }
        return S;
    }
};

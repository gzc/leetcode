class Solution {
public:
    string removeDuplicates(string S) {
        int i = 0;
        
        for (char ch : S) {
            if (i != 0 && ch == S[i-1]) {
                i--;
            } else {
                S[i] = ch;
                i++;
            }
        }
        
        return S.substr(0, i);
    }
};

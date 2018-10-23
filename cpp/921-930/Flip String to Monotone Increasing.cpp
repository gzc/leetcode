class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int rightZero = 0;
        for (char ch : S) if (ch == '0') rightZero++;
        
        int ans = min(rightZero, (int)S.size() - rightZero);
        
        int leftOne = 0;
        for (int i = 0; i < S.size(); i++) {
            ans = min(ans, rightZero + leftOne);
            if (S[i] == '1') leftOne++;
            else rightZero--;
        }
        
        return ans;
    }
};

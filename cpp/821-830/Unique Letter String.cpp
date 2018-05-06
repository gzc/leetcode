class Solution {
public:
    int uniqueLetterString(string S) {
        int ans = 0;
        map<char, int> lastPos, lastlastPos;
        for (int i = 0; i < 128; i++) { lastPos[i] = lastlastPos[i] = -1; }
        int tmp = 0;
        
        for (int i = 0; i < S.length(); i++) {
            char ch = S[i];
            if (lastPos[ch] < 0) {
                // ....A  we should add the previous
                tmp += (i - lastPos[ch]);
            } else {
                // A...A....A  we should add the second half and remove the first half
                tmp += (i - lastPos[ch]);
                tmp -= (lastPos[ch] - lastlastPos[ch]);
                lastlastPos[ch] = lastPos[ch];
            }
            ans += tmp;
            lastPos[ch] = i;
        }
        
        return ans;
    }
};

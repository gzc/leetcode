class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int cnt = 0;
        
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i] != '-') {
                if(cnt == 0 && !ans.empty()) ans.push_back('-');
                ans.push_back(toupper(S[i]));
                cnt = (cnt + 1) % K;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

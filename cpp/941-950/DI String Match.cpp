class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans(S.size() + 1);
        
        int low = 0;
        int high = S.size();
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'I') {
                ans[i] = low;
                low++;
            } else {
                ans[i] = high;
                high--;
            }
        }
        ans[S.size()] = low;
        return ans;
    }
};

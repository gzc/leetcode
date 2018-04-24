// Time Complexity: O(n)
// Space COmplexity: O(n)

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans(S.length(), 0);
        int previous = -1;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) previous = i;
            ans[i] = previous < 0 ? INT_MAX : i - previous;
        }
        
        int next = INT_MAX;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] == C) next = i;
            int temp = next == INT_MAX ? INT_MAX : next - i;
            ans[i] = min(ans[i], temp);
        }
        
        return ans;
    }
};

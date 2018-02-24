class Solution {
    
    void dfs(string S, int i, vector<string>& result) {
        if (i == S.length()) {
            result.push_back(S);
            return;
        }
        if (isdigit(S[i])) {
            dfs(S, i+1, result);
        } else {
            S[i] = tolower(S[i]);
            dfs(S, i+1, result);
            S[i] = toupper(S[i]);
            dfs(S, i+1, result);
        }
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(S, 0, result);
        return result;
    }
};

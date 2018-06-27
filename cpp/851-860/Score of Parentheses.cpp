class Solution {
    
    int dfs(const string& S, int& i) {
        int sum = 0;
        
        for (i; i < S.length(); i++) {
            if (S[i] == '(') {
                i++;
                sum += dfs(S, i);
            } else if (S[i] == ')') {
                if (sum == 0) return 1;
                return 2*sum;
            }
        }
        
        return sum;
    }
    
public:
    int scoreOfParentheses(string S) {
        int i = 0;
        return dfs(S, i);
    }
};

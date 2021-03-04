class Solution {
    
    void dfs(string s, int open, int close, vector<string>& parentheses) {
        if (close < open) {
            return;
        }
        
        if (open == 0) {
            string temp(close, ')');
            s += temp;
            parentheses.push_back(s);
        } else {
            dfs(s + "(", open - 1, close, parentheses);
            dfs(s + ")", open, close - 1, parentheses);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;
        dfs("", n, n, parentheses);
        return parentheses;
    }
};

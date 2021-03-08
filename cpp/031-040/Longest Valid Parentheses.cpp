// Solution 1: DP
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == ')') {
                if (s[i-1] == '(') {
                    int val = i - 2 >= 0 ? dp[i-2] : 0;
                    dp[i] = 2 + val;
                } else {
                    int ind = i - dp[i-1] - 1;
                    if (ind >= 0 && s[ind] == '(') {
                        int val = ind > 0 ? dp[ind - 1] : 0;
                        dp[i] = 2 + dp[i-1] + val;
                    }
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

// Solution 2: stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mystack;
        mystack.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int t = mystack.top();
            if (t != -1 && s[i] == ')' && s[t]=='(') {
                mystack.pop();
                res = max(res, i - mystack.top());
            } else {
                mystack.push(i);
            }
        }
        return res;
    }
};

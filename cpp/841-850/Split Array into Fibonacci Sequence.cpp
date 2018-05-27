class Solution {
    
    bool dfs(long n1, long n2, string& S, int pos, int l, vector<int>& ans) {
        if (pos >= S.length()) {
            return l >= 3;
        }
        long n3 = n1 + n2;
        if (n1 > INT_MAX || n2 > INT_MAX || n3 > INT_MAX) return false;
        string s = to_string(n3);
        int len = s.length();
        if (S.length() - pos < len) return false;
        if (S.substr(pos, len) != s) return false;
        ans.push_back(n3);
        bool f = dfs(n2, n3, S, pos + len, l+1, ans);
        if (f) return true;
        ans.pop_back();
        return false;
    }
    
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if (S.size() < 3) return ans;
        int n = S.length();
        
        for (int len1 = 1; len1 <= min(10, n/2+1); len1++) {
            string str1 = S.substr(0, len1);
            if (str1[0] == '0' && len1 > 1) continue;
            long num1 = stol(str1);
            ans.push_back(num1);
            for (int len2 = 1; len2 <= min(10, n/2+1); len2++) {
                string str2 = S.substr(len1, len2);
                if (str2[0] == '0' && len2 > 1) break;
                long num2 = stol(str2);
                ans.push_back(num2);
                if (dfs(num1, num2, S, len1+len2, 2, ans)) return ans;
                ans.pop_back();
            }
            ans.pop_back();
        }
        
        return ans;
    }
};

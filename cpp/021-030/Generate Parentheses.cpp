class Solution {
    
    void help(string s, int n, int m, vector<string>& result) {
        if(m < n) return;
        
        if(n == 0) {
            string temp(m, ')');
            s += temp;
            result.push_back(s);
        } else {
            help(s+"(", n-1, m, result);
            help(s+")", n, m-1, result);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        help("", n, n, result);
        return result;
    }
};

class Solution {
    int numRepetition(const string &s, const string &t) {
        int cnt = 0,i = 0;
        while (i < s.length()) {
            if (s.substr(i, t.length()) != t) break;
            cnt++;
            i += t.length();
        }
        return cnt;
    }
    
    string dfs(const string& s, unordered_map<string, string> &m) {
        if (s.length() < 5) return s;
        if (m.count(s) > 0) return m[s];
        string res(s);
        for (int i = 0; i < s.length(); i++) {
            string s1 = s.substr(0, i+1);
            int cnt = numRepetition(s, s1);
            string t;
            for (int k = 1; k <= cnt; k++) {
                if (k == 1) t = s1 + dfs(s.substr(i+1), m);
                else t = to_string(k) + "[" + dfs(s1, m) + "]" + dfs(s.substr(k*s1.length()), m);
                if (t.length() < res.length()) res=t;            
            }
        }
        return m[s] = res;
    }
    
public:
    string encode(string s) {
        unordered_map<string,string> m;
        return dfs(s,m);
    }
};

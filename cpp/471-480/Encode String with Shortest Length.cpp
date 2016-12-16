class Solution {
    
    map<string, string> cache;
    
    string solve(string str) {
        string ans(str);
        int len = str.length();
        for (int i = 1; i <= len/2; i++) {
            if (len % i != 0) continue;
            string part = str.substr(0, i);
            int dups = len / i;
            bool ff = true;
            for (int k = 0; k < dups; k++) {
                int idx = k * i;
                bool f = true;
                for (int j = 0; j < i; j++) {
                    if (str[idx + j] != str[j]) {
                        f = false;
                        break;
                    }
                }
                if (f == false) { ff = false; break; }
            }
            if (ff == false) continue;
            string temp = to_string(dups) + '[' + encode(part) + ']';
            if (temp.length() < ans.length()) ans = temp;
        }
        //cout << str << " : " << ans << endl;
        return ans;
    }
    
public:
    string encode(string s) {
        int len = s.length();
        if (len <= 1) return s;
        if (cache.count(s) > 0) return cache[s];
        string ans(s);
        for (int i = 1;i <= len; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            string temp = solve(left) + encode(right);
            if (temp.length() < ans.length()) ans = temp;
        }
        cache[s] = ans;
        return ans;
    }
};

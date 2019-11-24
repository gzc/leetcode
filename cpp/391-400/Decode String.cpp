class Solution {
    
    string solve(const string& s, int& i) {
        string result;
        while (i < s.length() && s[i] != ']') {
            int d = 0;
            if (isdigit(s[i])) {
                while (isdigit(s[i])) {
                    d = 10 * d + (s[i] - '0');
                    i++;
                }
            }
            
            if (s[i] == '[') {
                i++;
                string temp = solve(s, i);
                i++;
                while (d-- > 0) result += temp;
            } else {
                result += s[i];
                i++;
            }
                       
        }
        return result;
    }
    
public:
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};

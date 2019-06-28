class Solution {
    
    bool IsValid(const string& str, const string& candidate) {
        for (int i = 0; i < str.length(); i += candidate.length()) {
            if (str.substr(i, candidate.length()) != candidate) {
                return false;
            }
        }
        return true;
    }
    
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int gcd = __gcd(m, n);
        
        string candidate = str1.substr(0, gcd);
        
        if (!IsValid(str1, candidate)) return "";
        if (!IsValid(str2, candidate)) return "";
        
        return candidate;
    }
};

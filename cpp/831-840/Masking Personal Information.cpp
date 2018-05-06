class Solution {
    
    string processEmail(string& S) {
        for (int i = 0; i < S.length(); i++) S[i] = tolower(S[i]);
        int index = S.find('@');
        string ans;
        ans.push_back(S[0]);
        ans += "*****" + S.substr(index-1);
        return ans;
    }
    
    string processPhone(const string& S) {
        string filterS;
        for (char ch : S) if (isdigit(ch)) filterS += ch;
        string ans;
        int num = filterS.length() - 10;
        if (num > 0) {
            ans += '+';
            ans += string(num, '*');
            ans += '-';
        }
        ans += "***-***-";
        ans += filterS.substr(filterS.length() - 4);
        return ans;
    }
    
public:
    string maskPII(string S) {
        if (S.find('@') != string::npos) {
            return processEmail(S);
        } else {
            return processPhone(S);
        }
    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        
        for (string email : emails) {
            string ans;
            int idx = email.find('@');
            for (char ch : email) {
                if (ch == '.') continue;
                if (ch == '+' || ch == '@') break;
            }
            ans = ans + email.substr(idx, email.size() - idx);
            uniqueEmails.insert(ans);
        }
        
        return uniqueEmails.size();
    }
};

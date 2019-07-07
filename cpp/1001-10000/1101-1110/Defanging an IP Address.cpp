class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        
        for (char ch : address) {
            if (ch == '.') {
                ans = ans + '[' + '.' + ']';
            } else {
                ans = ans + ch;
            }
        }
        
        return ans;
    }
};

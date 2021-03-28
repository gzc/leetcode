class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mymap;
        for (const vector<string>& k : knowledge) {
            mymap[k[0]] = k[1];
        }
        
        string ans;
        string key;
        bool in_bracket = false;
        for (char ch : s) {
            if (ch == '(') {
                in_bracket = true;
            } else if (ch == ')') {
                in_bracket = false;
                if (mymap.count(key) > 0) {
                    ans += mymap[key];
                } else {
                    ans += "?";
                }
                key.clear();
            } else {
                if (in_bracket) {
                    key += ch;
                } else {
                    ans += ch;
                }
            }
        }
        
        return ans;
    }
};

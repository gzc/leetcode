class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> p(s.length()+1, false);
        p[0]=true;
        for(int i = 0;i < s.length();i++) {
            for(int j = 0;j <= i;j++) {
                if(p[j] == true) {
                    string tmp = s.substr(j,i+1-j);
                    if (dict.find (tmp) != dict.end()) {
                        p[i+1] = true;
                        break;
                    }
                }
            }
        }
        return p[s.length()];
    }
};

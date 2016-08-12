class Solution {
    
    unordered_map<string, vector<string>>m;
    
public:
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (m.count(s) > 0) return m[s];
        vector<string> words;
        int len = s.length();
        for(int i = 1;i <= len;i++) {
            string first = s.substr(0, i);
            unordered_set<string>::const_iterator got = dict.find(first);
            if (got != dict.end()) {
                if(i == len)
                    words.push_back(first);
                else {
                    string remain = s.substr(i);
                    vector<string> remainVec = wordBreak(remain, dict);
                    for (int k = 0;k < remainVec.size();k++)
                        words.push_back(first + " " + remainVec[k]);
                }
            }
        }
        m[s] = words;
        return words;
    }
};

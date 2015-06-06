class Solution {
    
    unordered_map<string, vector<string>>m;
    
public:
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(m.count(s) > 0) return m[s];
        vector<string> words;
        int len = s.length();
        for(int i = len-1;i >= 0;i--)
        {
            string last = s.substr(i,len-i);
            unordered_set<string>::const_iterator got = dict.find (last);
            if ( got != dict.end() ) {
                if(i == 0)
                    words.push_back(last);
                else {
                    string remain = s.substr(0,i);
                    vector<string> remainVec = wordBreak(remain, dict);
                    for(int k = 0;k < remainVec.size();k++)
                        words.push_back(remainVec[k] + " " + last);
                }
            }
        }
        m[s] = words;
        return words;
    }
};

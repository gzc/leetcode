class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        if (indexes.empty() || S.empty()) return S;
        map<int, pair<string, string>> mymap;
        for (int i = 0; i < indexes.size(); i++) {
            mymap[indexes[i]] = make_pair(sources[i], targets[i]);
        }
        
        stringstream ss;
        for (int i = 0; i < S.length(); i++) {
            if (mymap.find(i) != mymap.end()) {
                string s = mymap[i].first;
                string t = mymap[i].second;
                if (i + s.length() > S.length()) {
                    ss << S[i];
                } else {
                    string temp = S.substr(i, s.length());
                    if (temp == s) {
                        ss << t;
                        i += (s.length() - 1);
                    } else {
                        ss << S[i];
                    }
                }
            } else {
                ss << S[i];
            }
        }
        return ss.str();
    }
};

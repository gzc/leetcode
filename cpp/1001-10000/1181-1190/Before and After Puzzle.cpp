class Solution {
    
    string getfirst(string& s) {
        size_t pos = s.find(' ');
        if (pos == string::npos) return s;
        return s.substr(0, pos);
    }
    
    string getlast(string& s) {
        size_t pos = s.find_last_of(' ');
        if (pos == string::npos) return s;
        return s.substr(pos+1);
    }
    
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        map<string, vector<int>> firstmap;
        map<string, vector<int>> lastmap;
        for (int i = 0; i < phrases.size(); i++) {
            string& s = phrases[i];
            string first = getfirst(s);
            firstmap[first].push_back(i);
            string last = getlast(s);
            lastmap[last].push_back(i);
        }
        
        set<string> ans;
        for (auto& it : lastmap) {
            const string& s = it.first;
            if (firstmap.count(s) > 0) {
                vector<int>& seconds = firstmap[s];
                vector<int>& firsts = it.second;
                for (int i : firsts) {
                    string original_first = phrases[i];
                    string f;
                    size_t pos = original_first.find_last_of(' ');
                    if (pos == string::npos) f = "";
                    else f = original_first.substr(0, pos+1);
                    for (int j : seconds) {
                        if (i == j) continue;
                        string original_second = phrases[j];
                        ans.insert(f + original_second);
                    }
                }
            }
        }
        vector<string> return_ans(ans.begin(), ans.end());
        return return_ans;
    }
};

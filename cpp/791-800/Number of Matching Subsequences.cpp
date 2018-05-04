class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> waiting[128];
        for (auto &w : words)
            waiting[w[0]].push_back(w.c_str());
        for (char c : S) {
            vector<const char*> advance = waiting[c];
            waiting[c].clear();
            for (const char* it : advance)
                waiting[*++it].push_back(it);
        }
        return waiting[0].size();
    }
};

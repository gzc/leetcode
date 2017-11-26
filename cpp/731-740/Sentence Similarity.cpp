class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        map<string, set<string>> mymap;
        for (const auto& pair : pairs) {
            mymap[pair.first].insert(pair.second);
            mymap[pair.second].insert(pair.first);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) continue;
            if (mymap[words1[i]].count(words2[i]) == 0) return false;
        }
        return true;
    }
};

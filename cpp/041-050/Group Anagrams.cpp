class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mymap;
        for (const string& str : strs) {
            string key(str);
            sort(key.begin(), key.end());
            mymap[key].emplace_back(str);
        }
        vector<vector<string>> result;
        for (const auto& it : mymap) result.emplace_back(it.second);
        return result;
    }
};

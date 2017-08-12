class Solution {
    
    bool isS1subsOfS2(const string &s1, const string &s2){
        if (s1.length() >= s2.length()) return false;
        int j = 0, i = 0;
        for(; i < s1.size(); ++i){
            while(j < s2.size() && s1[i] != s2[j]) ++j;
            if(j == s2.size())
               return false;
            ++j;
        }
        return true;
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> m;
        for(const string& str : strs) ++m[str];
        vector<pair<string, int>> v;
        for(const auto &e : m) v.push_back(e);
        
        auto cmp = [](const pair<string,int> &a, const pair<string,int> &b) {
            return a.first.size() > b.first.size();
        };
        sort(v.begin(), v.end(), cmp);
        
        for (int i = 0; i < v.size(); ++i) {
           if(v[i].second == 1) {
               int j = 0;
               for(; j < i; ++j)
                 if(isS1subsOfS2(v[i].first, v[j].first))
                     break;
               if(j == i) return v[i].first.size();
           }
        }
        return -1;
    }
};

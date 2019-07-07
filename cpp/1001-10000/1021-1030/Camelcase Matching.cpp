class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        
        for (const string& query : queries) {
            
            int i = 0;
            bool find = true;
            
            for (int j = 0; j < query.length(); j++) {
                if (i >= pattern.size()) {
                    if (isupper(query[j])) {
                        find = false;
                        break;
                    }
                    continue;
                }
                char target = pattern[i];
                if (target == query[j]) {
                    i++;
                } else if (isupper(query[j])) {
                    find = false;
                    break;
                }
            }
            
            find &= i >= pattern.size();
            
            ans.push_back(find);
        }
        
        return ans;
    }
};

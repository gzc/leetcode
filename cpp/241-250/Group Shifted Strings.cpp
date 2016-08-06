class Solution {
    
    bool pattern_match(const string &s1, const string &s2)
    {
        if (s1.length() != s2.length()) return false;
        int v(-1);
        for (int i = 0;i < s1.length();i++)
        {
            int temp = (s2[i]-s1[i])%26;
            if (temp < 0) temp += 26;
            if (v < 0) v= temp;
            if (temp != v) return false;
        }
        return true;
    }
    
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        
        for (int i = 0;i < strings.size();i++)
        {
            string cur = strings[i];
            bool match(false);
            for (int j = 0;j < result.size();j++)
            {
                if (pattern_match(cur, result[j][0]))
                {
                    result[j].push_back(cur);
                    match = true;
                    break;
                }
            }
            if (!match)
            {
                vector<string> pattern;
                pattern.push_back(cur);
                result.push_back(pattern);
            }
        }
        
        for (int i = 0;i < result.size();i++)
            sort(result[i].begin(), result[i].end());
        return result;
    }
};

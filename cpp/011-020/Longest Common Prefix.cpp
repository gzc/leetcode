class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            const string& str = strs[i];
            
            int k = 0;
            while (k < min(prefix.length(), str.length())) {
                if (prefix[k] != str[k]) {
                    break;
                }
                k++;
            }
            
            prefix = prefix.substr(0, k);
        }
        
        return prefix;
    }
};

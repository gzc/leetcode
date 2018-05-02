class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        for (string& str: strs) {
            string copyStr(str);
            reverse(copyStr.begin(), copyStr.end());
            if (copyStr > str) str = copyStr;
        }
        
        string ans;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            
            string before, after;
            for (int k = 0; k < i; k++) before += strs[k];
            for (int k = i+1; k < strs.size(); k++) after += strs[k];
            
            for (int k = 0; k < str.length(); k++) {
                string strPrev = str.substr(0, k);
                string strNext = str.substr(k);
                string finalStr = strNext + after + before + strPrev;
                if (finalStr > ans) ans = finalStr;
            }
            
            reverse(str.begin(), str.end());
            for (int k = 0; k < str.length(); k++) {
                string strPrev = str.substr(0, k);
                string strNext = str.substr(k);
                string finalStr = strNext + after + before + strPrev;
                if (finalStr > ans) ans = finalStr;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool inBlock = false;
        string sf;
        for (const string &t : source) {
            for (int i = 0; i < t.size();) {
                if (!inBlock) {
                    if (i + 1 == t.size()) sf += t[i++];
                    else {
                        string m = t.substr(i,2);
                        if (m == "/*") inBlock = true, i+=2;
                        else if (m == "//") break;
                        else sf += t[i++];
                    }
                } else {
                    if (i + 1 == t.size()) i++;
                    else {
                        string m = t.substr(i,2);
                        if (m == "*/") inBlock = false, i+=2;
                        else i++;
                    }
                }
            }
            if (sf.size() && !inBlock) ans.push_back(sf), sf = "";
        }
        return ans;
    }
};

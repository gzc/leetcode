class Solution {
    
    static bool cmp(const string& a, const string& b) {
        return a > b;
    }
    
public:
    string makeLargestSpecial(string S) {
        if (S.length() == 0) return "";
        int cnt = 0;
        vector<string> groups;
        int start = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '1') {
                cnt++;
            } else {
                cnt--;
            }
            
            if (cnt == 0) {
                groups.push_back("1" + makeLargestSpecial(S.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }

        sort(begin(groups), end(groups), cmp);
        string result;
        result = accumulate(begin(groups), end(groups), result);
        return result;
    }
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (int i = 0; i < d.size(); i++) {
            int pi = 0, pj = 0;
            for (; pi < s.size() && pj < d[i].size(); pi++) {
                pj += s[pi] == d[i][pj];
            }
            if (pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
                ans = d[i];
        }
        return ans;
    }
};

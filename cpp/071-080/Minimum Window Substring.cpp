class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        int cnt = 0, start = 0, len = INT_MAX, first = 0;
        for (char c : t) {
            dict[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]]--;
            if (dict[s[i]] >= 0) {
                cnt++;
            }
            while (cnt == t.size()) {
                dict[s[start]]++;
                if (dict[s[start]] > 0) {
                    cnt--;
                }
                if (i - start + 1 < len) {
                    len = i - start + 1;
                    first = start;
                }
                start++;
            }
        }
        return len == INT_MAX ? "" : s.substr(first, len);
    }
};

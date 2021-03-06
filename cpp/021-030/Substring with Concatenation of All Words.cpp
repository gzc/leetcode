class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> dict;
        int len = words[0].size();
        int n = s.length(), m = words.size();
        for (const string& word : words) {
            dict[word]++;
        }
        for (int i = 0; i < len; i++) {
            int cnt = 0;
            unordered_map<string, int> copy = dict;
            for (int j = i; j <= n - len; j += len) {
                string cur = s.substr(j, len);
                copy[cur]--;
                if (copy[cur] >= 0) {
                    cnt++;
                }
                
                int pop_start = j - m * len;
                if (pop_start >= 0) {
                    string pop_word = s.substr(pop_start, len);
                    copy[pop_word]++;
                    if (copy[pop_word] > 0) {
                        cnt--;
                    }
                }
                if (cnt == m) {
                    res.push_back(pop_start + len);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        string w, res;
        int c = 0;
        while (iss >> w) {
            if (ban.find(w) == ban.end() && ++count[w] > c) {
                res = w;
                c = count[w];
            }
        }
        return res;
    }
};

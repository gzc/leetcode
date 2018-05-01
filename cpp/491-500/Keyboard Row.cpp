class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a[3] = {
            "QWERTYUIOPqwertyuiop",
            "ASDFGHJKLasdfghjkl",
            "ZXCVBNMzxcvbnm",
        };
        vector<string> ans;
        for (int index = 0; index < 3; ++ index) {
            for (auto& word: words) {
                int cnt = 0;
                for (auto ch: word) {
                    if (a[index].find(ch) != string::npos) {
                        cnt ++;
                    }
                }
                if (cnt == word.size()) {
                    ans.push_back(word);
                }
            }
        }
        return ans;
    }
};

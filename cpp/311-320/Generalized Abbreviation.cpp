class Solution {
    
    void help(int i, string &word, vector<string>& result, int previous, string temp) {
        if(i >= word.length()) {
            if(previous != 0) temp = temp + to_string(previous);
            result.push_back(temp);
            return;
        }
        string num("");
        if(previous != 0) num = to_string(previous);
        string _temp = temp+num+word[i];
        help(i+1, word, result, 0, _temp);
        help(i+1, word, result, previous+1, temp);
    }
    
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        help(0, word, result, 0, "");
        return result;
    }
};
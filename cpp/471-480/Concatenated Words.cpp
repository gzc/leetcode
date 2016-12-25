class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result; 
        auto mycomp = [&](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        unordered_set<string> mp;
        for(string& word: words) {
            if(wordBreak(word, mp)) result.push_back(word); // We don't need to insert this word, because it can be concatenated from other words.
            else mp.insert(word); 
        }
        return result;
    }
    
private:
    bool wordBreak(const string& s, const unordered_set<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int k = i-1; k >= 0; k--) {
                if(dp[k] && wordDict.find(s.substr(k, i-k)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

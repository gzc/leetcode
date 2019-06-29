class Solution {
    
    int dfs(const string& word, const unordered_set<string>& dictionary, unordered_map<string, int>& cache) {
        unordered_map<string, int>::iterator it = cache.find(word);
        if (it != cache.end()) {
            return it->second;
        }
        
        int ans = 1;
        for (int i = 0; i < word.size(); i++) {
            string c_word = word.substr(0, i) + word.substr(i+1);
            if (dictionary.count(c_word) > 0) {
                ans = max(ans, 1 + dfs(c_word, dictionary, cache));
            }
        }
        return cache[word] = ans;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> dictionary(begin(words), end(words));
        unordered_map<string, int> cache;
        
        int ans = 1;
        for (const string& word : words) {
            ans = max(ans, dfs(word, dictionary, cache));
        }
        
        return ans;
    }
};

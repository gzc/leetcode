class Solution {
    
    int getF(const string& word) {
        char ch = word[0];
        for (int i = 1; i < word.size(); i++) {
            if (ch > word[i]) ch = word[i];
        }

        int f = 0;
        for (char c : word) if (c == ch) f++;
        return f;
    }
    
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> v;
        
        for (auto& word : words) {
            int f = getF(word);
            v.push_back(f);
        }
        
        vector<int> ans;
        for (auto& query : queries) {
            int f = getF(query);
            int c = 0;
            for (int e : v) if (f < e) c++;
            ans.push_back(c);
        }
        
        return ans;
    }
};

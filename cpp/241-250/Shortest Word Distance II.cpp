class WordDistance {
    
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        const vector<int>& v1 = m[word1];
        const vector<int>& v2 = m[word2];
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        
        while (i < v1.size() && j < v2.size()) {
            int i1 = v1[i];
            int i2 = v2[j];
            res = min(abs(i1-i2), res);
            if(i1 > i2) {
                j++;
            } else {
                i++;
            }
        }

        return res;
    }
};

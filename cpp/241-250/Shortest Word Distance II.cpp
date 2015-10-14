class WordDistance {
    
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string>& words) {
        for(int i = 0;i < words.size();i++)
            m[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> v1 = m[word1];
        vector<int> v2 = m[word2];
        int i(0),j(0),res(INT_MAX);
        while(i < v1.size() && j < v2.size())
        {
            int i1 = v1[i];
            int i2 = v2[j];
            res = min(abs(i1-i2), res);
            if(i1 > i2)
                j++;
            else
                i++;
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
class Solution {
    
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size()) {
            if(word1.substr(i) > word2.substr(j)) {
                ans.push_back(word1[i]);
                i++;
            } else {
                ans.push_back(word2[j]);
                j++;
            }
        }
        
        if(i == word1.size()) {
            ans += word2.substr(j);
        } else if(j == word2.size()) {
            ans += word1.substr(i);
        }
        
        return ans;
    }
};

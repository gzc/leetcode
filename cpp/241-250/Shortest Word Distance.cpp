class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int index1(-1), index2(-1), shortest(INT_MAX);
        for(int i = 0;i < words.size();i++)
        {
            if(words[i] == word1) {
                index1 = i;
            } else if(words[i] == word2) {
                index2 = i;
            }
            
            if(index1 == -1 || index2 == -1) continue;
            shortest = min(abs(index1 - index2), shortest);
        }
        
        return shortest;
    }
};
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1(-1), index2(-1), shortest(INT_MAX);
        
        if(word1 == word2) {
            int i = 0;
            while(index1 == -1)
            {
                if(words[i] == word1) index1 = i;
                i++;
            }
            
            while(i < words.size())
            {
                if(words[i] == word1)
                {
                    shortest = min(i - index1, shortest);
                    index1 = i;
                }
                i++;
            }
        }
        
        else {
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
        }
        
        return shortest;
    }
};
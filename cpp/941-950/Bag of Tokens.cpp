class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        
        int i = 0, j = tokens.size() - 1;
        int points = 0;
        
        while (true) {
            while (i <= j && P >= tokens[i]) {
                points++;
                P -= tokens[i];
                i++;
            }
            
            if (i >= j || points <= 0) break;
            
            P += tokens[j];
            j--;
            points--;
        }
        
        return points;
    }
};

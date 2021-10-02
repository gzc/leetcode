class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> p(m+1, vector<int>(n+1));

        for (int i = 0;i <= m;i++)
            p[i][0] = i;
        for (int j = 0;j <= n;j++)
            p[0][j] = j;
        
        for (int i = 1;i <= m;i++) {
            for (int j = 1;j <= n;j++) {
                
                if (word1[i-1] == word2[j-1]) {
                    p[i][j] = p[i-1][j-1];
                } else {
                    p[i][j] = min(1 + p[i-1][j-1], 1+min(p[i][j-1], p[i-1][j]));
                }
                
            }
        }
        
        return p[m][n];
    }
};

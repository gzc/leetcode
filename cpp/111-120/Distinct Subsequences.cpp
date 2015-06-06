class Solution {
public:
    int numDistinct(string S, string T) {
        
        int n = S.length();
        int m = T.length();
        
        int p[n+1][m+1];
        memset(p, 0, sizeof(p));
        
        for(int k = 0;k <= n;k++)
            p[k][0] = 1;
        
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                p[i][j] = p[i-1][j];
                if(S[i-1] == T[j-1])
                    p[i][j] += p[i-1][j-1];
            }
        }
        
        return p[n][m];
    }
    
};

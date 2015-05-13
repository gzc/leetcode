class Solution {
public:
    int numTrees(int n) {
        
        int *p = new int[n+1];
        memset(p, 0, 4*(n+1));
        p[0] = p[1] = 1;
        
        for(int i = 2;i <= n;i++)
            for(int k = 0;k < n;k++)
                p[i] += p[k]*p[i-k-1];
        
        return p[n];
    }
};

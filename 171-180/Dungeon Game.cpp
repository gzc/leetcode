class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        
        int M = dungeon.size();
        int N = dungeon[0].size();
        
        vector<vector<int>> v(M, vector<int>(N, 0) );
        
        for(int i = M-1;i >= 0;i--) {
            
            for(int j = N-1;j >=0;j--) {
                if(i == M-1 && j == N-1) {
                    v[i][j] = max(1, 1 - dungeon[i][j]);
                } else if(i == M-1) {
                    v[i][j] = max(1, v[i][j+1] - dungeon[i][j]);
                } else if(j == N-1) {
                    v[i][j] = max(1, v[i+1][j] - dungeon[i][j]);
                } else {
                    v[i][j] = max(1, min(v[i+1][j],v[i][j+1]) - dungeon[i][j]);
                }
            }
        }

        return v[0][0];
    }
};

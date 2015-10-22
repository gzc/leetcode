class Solution {
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int result(0);
        vector<int>vx,vy;
        
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[i].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    vx.push_back(j);
                    vy.push_back(i);
                }
            }
        }
        
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        int midx = vx[vx.size()/2];
        int midy = vy[vy.size()/2];
        
        for(int i = 0;i < vx.size();i++)
        {
            result += abs(vx[i] - midx) + abs(vy[i] - midy);
        }
        
        return result;
    }
};
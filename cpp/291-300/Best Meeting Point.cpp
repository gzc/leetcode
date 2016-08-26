class Solution {
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int result(0);
        vector<int>vx, vy;
        
        for (int i = 0;i < grid.size();i++) {
            for (int j = 0;j < grid[i].size();j++) {
                if (grid[i][j] == 1) {
                    vx.push_back(j);
                    vy.push_back(i);
                }
            }
        }
        
        int half_num = vx.size()/2;
        std::nth_element (vx.begin(), vx.begin()+half_num, vx.end());
        std::nth_element (vy.begin(), vy.begin()+half_num, vy.end());
        int midx = vx[half_num];
        int midy = vy[half_num];
        
        for (int i = 0;i < vx.size();i++)
            result += abs(vx[i] - midx) + abs(vy[i] - midy);
        
        return result;
    }
};

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        
        for (auto& v : grid) {
            for (int v : v) {
                ans += (v > 0);
            }
            ans += *(max_element(v.begin(), v.end()));
        }
        
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                temp = max(temp, grid[j][i]);
            }
            ans += temp;
        }
        
        return ans;
    }
};

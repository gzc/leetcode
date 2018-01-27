class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size() - 1; i++) {
            for (int j = i + 1; j < grid.size(); j++) {
                int counter = 0;
                for (int k = 0; k < grid[0].size(); k++) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) counter++;
                }
                if (counter > 0) ans += counter * (counter - 1) / 2;
            }
        }
        return ans;
    }
};


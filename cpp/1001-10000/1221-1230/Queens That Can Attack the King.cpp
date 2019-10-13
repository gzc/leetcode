class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        set<pair<int, int>> q;
        for (auto& queen : queens) {
            q.insert({queen[0], queen[1]});
        }
        
        for (auto& dir : directions) {
            int x = king[0];
            int y = king[1];
            
            while (true) {
                x += dir.first;
                y += dir.second;
                if (x < 0 || y < 0 || x >= 8 || y >= 8) break;
                if (q.count({x,y}) > 0) {
                    ans.push_back({x, y});
                    break;
                }
            }
        }
        
        
        return ans;
    }
};

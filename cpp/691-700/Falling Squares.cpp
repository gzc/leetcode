class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> ans;
        vector<tuple<int, int, int>> points; // x, y, sidelength
        int current = 0;
        
        for (const pair<int, int>& position : positions) {
            int top = position.second;
            
            // Find all previous squares that are in current width range
            for (const auto& point : points) {
                int x = get<0>(point);
                int y = get<1>(point);
                int length = get<2>(point);
                    
                if (x + length <= position.first) continue;
                if (position.first + position.second <= x) continue;
                top = max(top, y + position.second);
            }

            points.emplace_back(make_tuple(position.first, top, position.second));
            current = max(current, top);
            ans.push_back(current);
        }
        
        return ans;
    }
};

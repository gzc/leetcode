class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> myset;
        for (const vector<int>& point : points) {
            myset.insert({point[0], point[1]});
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                pair<int, int> a{points[i][0], points[j][1]};
                pair<int, int> b{points[j][0], points[i][1]};
                if (a.first != b.first && a.second != b.second &&
                    myset.count(a) > 0 && myset.count(b) > 0) {
                    int w = abs(a.first - b.first);
                    int h = abs(a.second - b.second);
                    ans = min(ans, w * h);
                }
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};

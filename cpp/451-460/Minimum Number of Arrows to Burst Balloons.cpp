class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int count = 0, arrow = INT_MIN;
        auto cmp = [&] (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        };
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < points.size(); i++)  {
            if (arrow != INT_MIN && points[i].first <= arrow) { continue; } //former arrow shot points[i] 
            arrow = points[i].second; // new arrow shot the end of points[i]
            count++;
        }
        return count;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [&](const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] <  b[0] * b[0] + b[1] * b[1]; 
        };
        
        nth_element(points.begin(), points.begin() + K, points.end(), cmp);
        // sort(points.begin(), points.end(), cmp);
        
        vector<vector<int>> ans(points.begin(), points.begin() + K);
        return ans;
    }
};

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        if (points[0] == points[1] || points[1] == points[2]) return false;
        
        int x1 = points[1][0] - points[0][0];
        int y1 = points[1][1] - points[0][1];
        int x2 = points[2][0] - points[1][0];
        int y2 = points[2][1] - points[1][1];
        
        if (x1 == 0 || x2 == 0) {
            return x1 != 0 || x2 != 0;
        }
        
        return fabs(1.0*y1/x1 - 1.0*y2/x2) > 10e-5;
    }
};

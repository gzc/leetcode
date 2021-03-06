class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1;
        int distance = INT_MAX;
        
        for (int i = 0; i < points.size(); i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int current_dis = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (current_dis < distance) {
                    distance = current_dis;
                    index = i;
                }
            }
        }
        
        return index;
    }
};

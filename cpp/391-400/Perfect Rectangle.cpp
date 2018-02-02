class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<string> points;
        int area = 0;
        int leftBottomX = INT_MAX, leftBottomY = INT_MAX, rightTopX = 0, rightTopY = 0;
        
        for (const auto& rectangle : rectangles) {
            leftBottomX = min(leftBottomX, rectangle[0]);
            leftBottomY = min(leftBottomY, rectangle[1]);
            rightTopX = max(rightTopX, rectangle[2]);
            rightTopY = max(rightTopY, rectangle[3]);
            
            string p1 = to_string(rectangle[0]) + ":" + to_string(rectangle[1]);
            string p2 = to_string(rectangle[2]) + ":" + to_string(rectangle[3]);
            string p3 = to_string(rectangle[0]) + ":" + to_string(rectangle[3]);
            string p4 = to_string(rectangle[2]) + ":" + to_string(rectangle[1]);
            
            vector<string> four{p1, p2, p3, p4};
            for (const string p : four) {
                if (points.count(p) > 0) {
                    points.erase(p);
                } else {
                    points.insert(p);
                }
            }
            
            area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
        }
        
        if (area != (rightTopX - leftBottomX) * (rightTopY - leftBottomY)) return false;
        if (points.size() != 4) return false;
        
        // Verfify thet are corner points
        if (points.count(to_string(leftBottomX) + ":" + to_string(leftBottomY)) == 0) return false;
        if (points.count(to_string(leftBottomX) + ":" + to_string(rightTopY)) == 0) return false;
        if (points.count(to_string(rightTopX) + ":" + to_string(leftBottomY)) == 0) return false;
        if (points.count(to_string(rightTopX) + ":" + to_string(rightTopY)) == 0) return false;
        
        return true;
    }
};

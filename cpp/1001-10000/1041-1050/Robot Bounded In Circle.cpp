class Solution {
    
    pair<int, int> getNextDirection(pair<int, int> d, char ch) {
        if (ch == 'L') {
            if (d.first == 0 && d.second == 1) {
                return {-1, 0};
            }
            if (d.first == -1 && d.second == 0) {
                return {0, -1};
            }
            if (d.first == 0 && d.second == -1) {
                return {1, 0};
            }
            if (d.first == 1 && d.second == 0) {
                return {0, 1};
            }
        } else {
            if (d.first == 0 && d.second == 1) {
                return {1, 0};
            }
            if (d.first == 1 && d.second == 0) {
                return {0, -1};
            }
            if (d.first == 0 && d.second == -1) {
                return {-1, 0};
            }
            if (d.first == -1 && d.second == 0) {
                return {0, 1};
            }
        }
        return {0, 0};
    }
    
    string GetKey(int x, int y, pair<int, int> d) {
        return to_string(x) + '-' + to_string(y) + '-' + to_string(d.first) + '-' + to_string(d.second);
    }
    
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> d = {0, 1};
        int x = 0, y = 0;
        
        for (char ch : instructions) {
            if (ch == 'G') {
                x += d.first;
                y += d.second;
            } else {
                d = getNextDirection(d, ch);
            }
        }
        
        if (x == 0 && y == 0) return true;
        if (d.first == 0 && d.second == 1) return false;
        return true;
        
    }
};

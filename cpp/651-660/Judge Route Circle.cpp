class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> pos{0, 0};
        for (char ch : moves) {
            if (ch == 'U') {
                pos.second++;
            } else if (ch == 'D') {
                pos.second--;
            } else if (ch == 'L') {
                pos.first--;
            } else {
                pos.first++;
            }
        }
        
        if (pos.first == 0 && pos.second == 0) return true;
        return false;
    }
};

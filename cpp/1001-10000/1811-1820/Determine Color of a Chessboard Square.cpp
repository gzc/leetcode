class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a') % 2) == ((coordinates[1] - '0') % 2);
    }
};

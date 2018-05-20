class Solution {
    int overlapLen(int a1, int a2, int b1, int b2) {
        if (a1 > b1) return overlapLen(b1, b2, a1, a2);
        int left = b1;
        int right = min(a2, b2);
        if (right <= left) return 0;
        return right - left;
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return overlapLen(rec1[0], rec1[2], rec2[0], rec2[2]) > 0 && overlapLen(rec1[1], rec1[3], rec2[1], rec2[3]) > 0;
    }
};

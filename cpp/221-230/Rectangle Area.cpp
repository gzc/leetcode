class Solution {
    
    int overlapLen(int a1, int a2, int b1, int b2) {
        if (a1 > b1) return overlapLen(b1, b2, a1, a2);
        int left = b1;
        int right = min(a2, b2);
        if (right <= left) return 0;
        return right - left;
    }
    
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        int width = overlapLen(A, C, E, G);
        int height = overlapLen(B, D, F, H);
        return area1 + area2 - width*height;
    }
};

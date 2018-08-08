class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles) total += ceil(p*1.0 / m);
            if (total > H) l = m + 1; else r = m;
        }
        return l;
    }
};

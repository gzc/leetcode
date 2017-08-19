class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int L = flowerbed.size();
        bool preUsed = false;
        for (int i = 0; i < L; i++) {
            if (flowerbed[i] == 1) {
                preUsed = true;
            } else {
                if (!preUsed) {
                    if (i + 1 == L || (i + 1 < L && flowerbed[i+1] == 0)) {
                        n--;
                        preUsed = true;
                    } else {
                        continue;
                    }
                } else {
                    preUsed = false;
                }
            }
        }
        return n <= 0;
    }
};

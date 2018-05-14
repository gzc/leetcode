class Solution {
public:
    int arrangeCoins(int n) {
        long ans = 0;
        long level = 1;
        while (ans + level <= n) {
            ans += level;
            level++;
        }
        return level - 1;
    }
};

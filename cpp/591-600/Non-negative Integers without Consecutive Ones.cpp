class Solution {
    int help(int num, int highestPos) {
        // 110010 -> 001111
        if ( (num >> (highestPos-2)) % 2 == 1) {
            int mask = 0;
            for (int i = 0; i < (highestPos - 2); i++) {
                mask = mask*2+1;
            }
            return mask;
        } else {
            // 1010 -> 0010
            int mask = 1 << (highestPos-1);
            return num ^ mask;
        }
    }
public:
    int findIntegers(int num) {
        if (num == 0) return 1;
        if (num == 1) return 2;
        if (num == 2 || num == 3) return 3;
        int dp[33] = {0};
        dp[0] = dp[1] = dp[2] = 1;
        int sum = 3;
        int highestPos = 0;
        int temp = num;
        while (temp > 0) {
            highestPos++;
            temp = temp >> 1;
        }
        for (int i = 3; i < highestPos; i++) {
            dp[i] = dp[i-2] + dp[i-1];
            sum += dp[i];
        }
        int remain = help(num, highestPos);
        return sum + findIntegers(remain);
    }
};

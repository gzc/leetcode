class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int num = 0;
        for (char ch : s) {
            num += (ch == 'L') ? 1 : -1;
            if (num == 0) ans++;
        }
        return ans;
    }
};

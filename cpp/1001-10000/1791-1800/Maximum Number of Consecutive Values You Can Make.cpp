class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int cur = 0;
        
        for (int coin : coins) {
            if (cur + 1 >= coin) {
                cur += coin;
            }
        }
        
        return cur + 1;
    }
};

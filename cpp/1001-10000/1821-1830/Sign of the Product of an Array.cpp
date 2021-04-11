class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for (int num : nums) {
            if (num > 0) continue;
            else if (num == 0) return 0;
            else res *= -1;
        }
        return res;
    }
};

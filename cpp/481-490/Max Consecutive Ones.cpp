class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool flag = false;
        int res = 0, tmp = 0;
        for (int v : nums) {
            if (v == 1) {
                tmp++;
                flag = true;
            } else {
                res = max(res, tmp);
                flag = false;
                tmp = 0;
            }
        }
        res = max(res, tmp);
        return res;
    }
};

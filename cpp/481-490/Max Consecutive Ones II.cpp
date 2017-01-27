class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0, zeros = 0, res = 0;
        for (; j < nums.size(); j++) {
            if (nums[j] == 0) zeros++;
            if (zeros > 1) {
                while (nums[i] == 1) i++;
                i++;
                zeros--;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};

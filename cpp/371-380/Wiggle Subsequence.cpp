class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int flag(0), count(1);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1] && (flag == -1 || count == 1)) {
                ++count;
                flag = 1;
            }
            else if (nums[i] < nums[i-1] && (flag == 1 || count == 1)) {
                ++count;
                flag = -1;
            }
        }
        return nums.size() == 0 ? 0 : count;
    }
};

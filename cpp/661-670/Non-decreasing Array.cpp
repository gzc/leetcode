class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i+1]) {
                ++cnt;
                // 2 3 3 2 4 => 2 3 3 3 4
                // 4 2 3 => 2 2 3
                // 3 4 2 3 => 3 3 2 3
                if (i > 0 && nums[i+1] < nums[i-1]) {
                    nums[i+1] = nums[i];
                }
                else nums[i] = nums[i+1];
            }
        }
        return cnt <= 1;
    }
};

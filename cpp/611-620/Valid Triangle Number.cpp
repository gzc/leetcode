class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if ((nums[left] + nums[right]) > nums[i]) {
                    result += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};

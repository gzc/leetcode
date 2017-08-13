class Solution {
    bool validate(int a, int b, int c) {
        if (a+b > c && a+c > b && b+c > a) return true;
        return false;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if (validate(nums[i], nums[left], nums[right])) {
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

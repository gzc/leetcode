class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, result = 0, product = 1;
        while (i < nums.size()) {
            while (j < nums.size() && nums[j] * product < k) {
                product *= nums[j];
                j++;
            }
            if (i == j) {
                i++;
                j++;
                continue;
            }
            result += (j-i);
            product /= nums[i];
            i++;
        }
        return result;
    }
};

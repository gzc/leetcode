class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxEndHere = nums[0];
        int minEndHere = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num >= 0) {
                maxEndHere = max(maxEndHere * num, num);
                minEndHere = min(minEndHere * num, num);
            } else {
                int temp = maxEndHere;
                maxEndHere = max(minEndHere * num, num);
                minEndHere = min(temp * num, num);
            }
            maxSoFar = max(maxEndHere, maxSoFar);
        }
        return maxSoFar;
    }
};

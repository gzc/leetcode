class Solution {
    
    int transform(int num, int a, int b, int c) {
        return a * num * num + b * num + c;
    }
    
    public:
        vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
            vector<int> res(nums.size());
            if (nums.size() == 0) return res;
            int i = 0, j = nums.size() - 1;
            if (a >= 0) {
                int index = nums.size() - 1;
                while (i <= j) {
                    if (transform(nums[i], a, b, c) > transform(nums[j], a, b, c)) {
                        res[index--] = transform(nums[i], a, b, c);
                        i++;
                    } else {
                        res[index--] = transform(nums[j], a, b, c);
                        j--;
                    }
                }
            } else {
                int index = 0;
                while (i <= j) {
                    if (transform(nums[i], a, b, c) < transform(nums[j], a, b, c)) {
                        res[index++] = transform(nums[i], a, b, c);
                        i++;
                    } else {
                        res[index++] = transform(nums[j], a, b, c);
                        j--;
                    }
                }
            }
            return res;
        }
};

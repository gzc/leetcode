class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for (int n : nums) {
            if (n != val) {
                nums[pos] = n;
                pos++;
            }
        }
        return pos;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (int n : nums) {
            if (pos == 0 || n > nums[pos-1]) {
                nums[pos] = n;
                pos++;
            }
        }
        return pos;
    }
};

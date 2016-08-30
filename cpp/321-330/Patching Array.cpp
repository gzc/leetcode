class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i(0), res(0);
        long miss(0);
        
        while (miss < n) {
            if (i < nums.size() && miss >= (nums[i] - 1) ) {
                miss += nums[i];
                i++;
            } else {
                res++;
                miss += (miss+1);
            }
        }
        return res;
    }
};

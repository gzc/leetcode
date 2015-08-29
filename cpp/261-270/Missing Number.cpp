class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int v = (1+n)*n/2;
        return v - s;
    }
};
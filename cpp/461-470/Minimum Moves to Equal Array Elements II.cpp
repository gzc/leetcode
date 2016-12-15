class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int median = nums[nums.size()/2];
        int res = 0;
        for (int v : nums) res += abs(median - v);
        return res;
    }
};

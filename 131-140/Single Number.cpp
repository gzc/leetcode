class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r(0);
        for(auto e : nums)
            r ^= e;
        return r;
    }
};

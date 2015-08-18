class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for(int e : nums)
        {
            if(e & diff)
                res[0] ^= e;
            else
                res[1] ^= e;
        }
        return res;
    }
};
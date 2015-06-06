class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> v(32, 0);
        for(auto e : nums)
        {
            for(int i = 0;i < 32;i++)
            {
                v[i] += e & 1;
                e = e >> 1;
            }
        }
        
        int result(0);
        for(int i = 0;i < 32;i++)
            if(v[i] % 3 != 0)
                result |= (1 << i);
                
        return result;
        
    }
};

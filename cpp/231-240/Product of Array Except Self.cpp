class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        res[0] = 1;
        
        for(int i = 1;i < nums.size();i++)
            res[i] = res[i-1]*nums[i-1];
        
        int temp(1);
        for(int i = nums.size()-1;i >= 0;i--)
        {
            res[i] *= temp;
            temp *= nums[i];
        }
        
        return res;
    }
};
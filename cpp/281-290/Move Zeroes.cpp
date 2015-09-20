class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int count(0), pos(0);
        
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] == 0) count++;
            else {
                nums[pos] = nums[i];
                pos++;
            }
        }
        
        for(int i = nums.size()-1; count > 0;i--,count--)
            nums[i] = 0;
        
    }
};
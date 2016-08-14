class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int i(0);
        
        while (i < nums.size()) {
            if (nums[i] != i+1 && nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
                continue;
            }
            i++;
        }
        
        for (int i = 0;i < nums.size();i++)
            if(nums[i] != i+1)
                return i+1;
        return nums.back()+1;
    }
};

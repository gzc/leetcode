class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        for (int i = 0;i < nums.size();i++) {
            if (i % 2 == 0 && (i+1) < nums.size() && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            if (i % 2 == 1 && (i+1) < nums.size() && nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
        }
        
    }
    
};

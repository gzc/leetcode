class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        if(nums.size() == 1) return;
        
        sort(nums.begin(), nums.end());
        
        int mid = (nums.size()-1)/2;
        
        int last = nums.size() - 1;
        if(last % 2 == 1) last--;
        
        int i = 1;
        while(last > i)
        {
            swap(nums[i], nums[last]);
            i += 2;
            last -= 2;
        }
        
    }
};
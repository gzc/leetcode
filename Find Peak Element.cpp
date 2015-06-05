class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int i(0),j(nums.size()-1);
        
        while(i < j)
        {
            int mid = (i+j) / 2;
            
            if(i == mid)
                return (nums[i] > nums[j] ? i : j);
                
            if(nums[mid] > nums[mid-1])
                i = mid;
            else
                j = mid-1;
        }
        
    }
};

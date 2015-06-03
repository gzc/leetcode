class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int i(0),j(nums.size()-1);
        int res(INT_MAX);
        
        while(i <= j)
        {
            if(i == j)
            {
                res = min(res, nums[i]);
                break;
            }
            int mid = (i+j)/2;
            res = min(res, nums[mid]);
            
            if(nums[mid] >= nums[i] && nums[mid] >= nums[j])
            {
                i = mid+1;
            } else if(nums[mid] <= nums[i] && nums[mid] <= nums[j]) {
                j = mid-1;
            } else {
                return min(res, nums[i]);
            }
        }
        
        return res;
        
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int left = 1, right = n;
        
        while(left < right)
        {
            int mid = (left+right)/2;
            
            int less(0),large(0), e(0);
            for(int i = 0;i < n;i++)
            {
                if(nums[i] < mid) less++;
                else if(nums[i] > mid) large++;
                else e++;
            }
            if(e > 1) return mid;
            if(less > mid - 1) right = mid - 1;
            else left = mid + 1;
        }
        
    }
    
};
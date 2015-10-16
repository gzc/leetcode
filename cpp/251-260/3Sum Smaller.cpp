class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int result(0);
        for(int i = 0;i < nums.size()-2;i++)
        {
            int j(i+1),k(nums.size()-1);
            int remain = target - nums[i];
            
            while(j < k)
            {
                if(nums[j] + nums[k] >= remain)
                {
                    k--;
                } else {
                    result += (k - j);
                    j++;
                }
            }
        }
        
        return result;
    }
};
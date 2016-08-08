class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int i(0),j(0),sum(0);
        int len(INT_MAX);
        nums.push_back(-1);
        
        while (j < nums.size())
        {
            if (sum >= s)
            {
                len = min(len, j-i);
                sum -= nums[i];
                i++;
            } else {
                sum += nums[j];
                j++;
            }
            
        }
        
        if (len == INT_MAX) return 0;
        return len;
    }
};

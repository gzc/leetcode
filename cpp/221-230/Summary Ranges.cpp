class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;
        if(nums.size() == 0) return res;
        int start(-1),end(-1);
        
        int i (0);
        while(i < nums.size())
        {
            start = end = nums[i];
            while(i+1 < nums.size() && nums[i] == nums[i+1]-1)
            {
                end++;
                i++;
            }
            if(start == end)
            res.push_back(to_string(start));
            else
            res.push_back(to_string(start)+"->"+to_string(end));
            i++;
        }
        
        return res;
        
    }
};

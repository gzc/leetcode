class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        
        int i(0);
        while (i < nums.size()) {
            int start(nums[i]);
            while (i+1 < nums.size() && nums[i] == nums[i+1]-1)
                i++;
            if (start == nums[i])
                res.push_back(to_string(start));
            else
                res.push_back(to_string(start)+"->"+to_string(nums[i]));
            i++;
        }
        
        return res;
    }
};

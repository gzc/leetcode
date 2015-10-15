class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> result;
        
        if(nums.size() == 0)
        {
            if(lower == upper) {
                string temp = to_string(lower);
                result.push_back(temp);
            } else {
                string temp = to_string(lower) + "->" + to_string(upper);
                result.push_back(temp);
            }
        }
        
        for(int i = 0;i < nums.size();i++)
        {
            if(i == 0) {
                if(nums[i] - lower >= 2) {
                    string temp = to_string(lower) + "->" + to_string(nums[i]-1);
                    result.push_back(temp);
                } else if(nums[i] - lower == 1) {
                    string temp = to_string(nums[i] - 1);
                    result.push_back(temp);
                } else {
                    
                }
            }
            
            if(i > 0) {
                if(nums[i] - nums[i-1] > 2) {
                    string temp = to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1);
                    result.push_back(temp);
                } else if(nums[i] - nums[i-1] == 2) {
                    string temp = to_string(nums[i]-1);
                    result.push_back(temp);
                }
            }
            
            
            if(i == nums.size() - 1) {
                if(upper - nums[i] >= 2) {
                    string temp = to_string(nums[i]+1) + "->" + to_string(upper);
                    result.push_back(temp);
                } else if(upper - nums[i] == 1) {
                    string temp = to_string(nums[i] + 1);
                    result.push_back(temp);
                } else {
                    
                }
            }
        }
        
        return result;
    }
};
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        
        int tmp = 0;
        for (int i = 1; i < nums.size(); i++) {
            tmp += (nums[i] - nums[0]);
        }
        ans.push_back(tmp);
        
        for (int i = 1; i < nums.size(); i++) {
            int diff = (nums[i] - nums[i-1]);
            int left = i - 1;
            int right = nums.size() - left - 2;
            
            tmp += (left*diff - right*diff);
            ans.push_back(tmp);
        }
        
        return ans;
    }
};

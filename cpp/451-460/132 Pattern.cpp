class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> mystack;
        
        for (int i = nums.size()-1; i >= 0; i--) {
            
            if (nums[i] < third) return true;
            
            while (!mystack.empty() && nums[i] > mystack.top()) {
                third = mystack.top();
                mystack.pop();
            }
            
            mystack.push(nums[i]);
        }
        
        return false;
    }
};

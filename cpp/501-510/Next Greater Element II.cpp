class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> mystack;
        int n = nums.size();
        nums.resize(2*nums.size());
        copy(nums.begin(), nums.begin()+n, nums.begin()+n);
        vector<int> result(n, 0);
        
        for (int i = nums.size()-1; i >= 0; i--) {
            
            while (!mystack.empty() && mystack.top() <= nums[i]) {
                mystack.pop();
            }
            
            if (i < n) {
                result[i] = mystack.empty() ? -1 : mystack.top();
            }
            
            mystack.push(nums[i]);
        }
        
        return result;
    }
};

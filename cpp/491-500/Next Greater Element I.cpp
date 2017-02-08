class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> mymap;
        stack<int> mystack;
        
        for (int i = nums.size()-1; i >= 0; i--) {
            
            while (!mystack.empty() && mystack.top() < nums[i]) {
                mystack.pop();
            }
            
            mymap[nums[i]] = mystack.empty() ? -1 : mystack.top();
            
            mystack.push(nums[i]);
            
        }
        
        vector<int> result;
        for (int v : findNums) {
            result.push_back(mymap[v]);
        }
        
        return result;
    }
};

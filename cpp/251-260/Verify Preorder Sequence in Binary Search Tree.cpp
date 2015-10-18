class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> mystack;
        int low = INT_MIN;
        
        for(int i = 0;i < preorder.size();i++)
        {
            if(preorder[i] < low) return false;
            while(!mystack.empty() && preorder[i] > mystack.top()) {
                low = mystack.top();
                mystack.pop();
            }
            mystack.push(preorder[i]);
        }
        
        return true;
    }
};
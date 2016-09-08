/*
        10
    5         15
 1    6     12   17
 
 10  5   1   6   15  12   17
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> mystack;
        int lower_bound_num(INT_MIN);
        
        for (int v : preorder) {
            if (v < lower_bound_num) return false;
            while (!mystack.empty() && v > mystack.top()) {
                lower_bound_num = mystack.top();
                mystack.pop();
            }
            mystack.push(v);
        }
        
        return true;
    }
};

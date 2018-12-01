class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> mystack;
        int i = 0;
        
        for (int e : pushed) {
            if (e == popped[i]) {
                // check if we should pop more elements.
                i++;
                while (!mystack.empty() && mystack.top() == popped[i]) {
                    mystack.pop();
                    i++;
                }
            } else {
                mystack.push(e);
            }
        }
        
        return mystack.empty();
    }
};

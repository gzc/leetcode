class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> mystack;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                mystack.push(i);
            } else if (ch == ')') {
                if (!mystack.empty()) {
                    mystack.pop();
                } else {
                    s[i] = '?';
                }
            }
        }
        
        while (!mystack.empty()) {
            s[mystack.top()] = '?';
            mystack.pop();
        }
        
        // https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
        s.erase(remove(s.begin(), s.end(), '?'), s.end());
        return s;
    }
};

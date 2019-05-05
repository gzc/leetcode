class Solution {
public:
    string removeOuterParentheses(string S) {
        string return_ans;
        stack<char> mystack;
        
        for (char ch : S) {
            if (mystack.empty()) {
                mystack.push(ch);
            } else {
                if (ch == '(') {
                    mystack.push(ch);
                    return_ans += '(';
                } else {
                    mystack.pop();
                    if (!mystack.empty()) {
                        return_ans += ')';
                    }
                }
            }
        }
        
        return return_ans;
    }
};

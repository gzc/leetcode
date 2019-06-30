class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops;
        stack<bool> nums;
        
        for (char ch : expression) {
            if (ch == '(' || ch == '&' || ch == '!' || ch == '|' || ch ==',') {
                ops.push(ch);
            } else if (ch == 't') {
                nums.push(true);
            } else if (ch == 'f') {
                nums.push(false);
            } else if (ch == ')') {
                vector<bool> tmp;
                tmp.push_back(nums.top());
                nums.pop();
                while (ops.top() == ',') {
                    tmp.push_back(nums.top());
                    nums.pop();
                    ops.pop();
                }
                ops.pop();
                char op = ops.top(); ops.pop();
                bool result = tmp.front();
                if (op == '&') {
                    for (int i = 1; i < tmp.size(); i++) {
                        result &= tmp[i];
                    }
                } else if (op == '|') {
                    for (int i = 1; i < tmp.size(); i++) {
                        result |= tmp[i];
                    }
                } else if (op == '!') {
                    result = 1 - result;
                }
                nums.push(result);
            }
        }
        
        return nums.top();
    }
};

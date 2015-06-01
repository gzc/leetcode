class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        for(int i = 0;i < tokens.size();i++)
        {
            string s = tokens[i];
            if(s == "+")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a+b);
            }
            else if(s == "-")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b-a);
            }
            else if(s == "*")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a*b);
            }
            else if(s == "/")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b/a);
            }
            else {
                int d = atoi(s.c_str());
                nums.push(d);
            }
        }
        return nums.top();
    }
    
};

class Solution {
    
    void apply(stack<int>& s, stack<char>& symbol) {
        char c = symbol.top();
        symbol.pop();
        int b = s.top();s.pop();
        int a = s.top();s.pop();
        if(c == '+') s.push(a+b);
        else s.push(a-b);
    }
    
public:
    int calculate(string s) {
        s = "(" + s + ")";
        stack<char> symbol;
        stack<int> nums;
        int v = 0;
        bool number = false;
        for (char e : s) {
            if (number && !isdigit(e)) {
                nums.push(v);
                v = 0;
                number = false;
            }
            
            if (e == ' ') continue;
            else if (e == ')') {
                while (symbol.top() != '(') {
                    apply(nums, symbol);
                }
                symbol.pop();
            } else if (e == '(') {
                symbol.push('(');
            } else if (isdigit(e)) {
                v = 10*v + (e-'0');
                number = true;
            } else if (e == '+' || e == '-') {
                if (!symbol.empty() && symbol.top() != '(') {
                    apply(nums, symbol);
                }
                symbol.push(e);
            }
        }

        return nums.top();
    }
};

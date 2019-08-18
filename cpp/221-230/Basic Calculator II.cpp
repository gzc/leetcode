class Solution {
    
    void apply(stack<int>& s, stack<char>& symbol) {
        char c = symbol.top();symbol.pop();
        int b = s.top();s.pop();
        int a = s.top();s.pop();
        if (c == '+') s.push(a+b);
        else if (c == '-') s.push(a-b);
        else if (c == '*') s.push(a*b);
        else s.push(a/b);
    }
    
public:
    int calculate(string s) {
        stack<char> symbol;
        stack<int>ss;
        int v = 0;
        bool number = false;
        for (char e : s) {
            if (number && !isdigit(e)) {
                ss.push(v);
                v = 0;
                number = false;
            }
            
            if (e == ' ') continue;
            if (isdigit(e)) {
                v = 10*v + (e-'0');
                number = true;
            } else if (e == '+' || e == '-') {
                while (!symbol.empty()) {
                    apply(ss, symbol);
                }
                symbol.push(e);
            } else if (e == '*' || e == '/') {
                if (!symbol.empty()) {
                    if (symbol.top() == '*' || symbol.top() == '/') {
                        apply(ss, symbol);
                    }
                }
                symbol.push(e);
            }
        }
        
        if (number)
            ss.push(v);
        
        while (!symbol.empty()) {
            apply(ss, symbol);
        }
        
        return ss.top();
    }
};

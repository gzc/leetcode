class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        for (int i = expression.size() - 1; i >= 0; --i) {
            char c = expression[i];
            if (!s.empty() && s.top() == '?') {
                s.pop();
                char first = s.top(); s.pop();
                s.pop();
                char second = s.top(); s.pop();
                s.push(c == 'T' ? first : second);
            } else {
                s.push(c);
            }
        }
        return string(1, s.top());
    }
};

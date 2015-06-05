class MinStack {
    
    stack<int> s1;
    stack<int> s2;
    
public:
    void push(int x) {
        s1.push(x);
        if(s2.empty() || s2.top() >= x) s2.push(x);
    }

    void pop() {
        int tmp = s1.top();
        s1.pop();
        if(tmp == s2.top())
            s2.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};

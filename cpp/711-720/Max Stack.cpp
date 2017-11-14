class MaxStack {
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || s2.top() <= x) s2.push(x);
    }
    
    int pop() {
        int tmp = s1.top();
        s1.pop();
        if (tmp == s2.top())
            s2.pop();
        return tmp;
    }
    
    int top() {
        return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int tmp = s2.top();
        s2.pop();
        
        stack<int> tmpStack;
        
        while (s1.top() < tmp) {
            tmpStack.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while (!tmpStack.empty()) {
            push(tmpStack.top());
            tmpStack.pop();
        }
        
        return tmp;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

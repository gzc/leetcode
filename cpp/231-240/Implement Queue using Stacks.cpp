class Queue {
public:
    
    stack<int>s1;
    stack<int>s2;
    
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int v = s1.top();
                s1.pop();
                s2.push(v);
            }
        }
        s2.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int v = s1.top();
                s1.pop();
                s2.push(v);
            }
        }
        return s2.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};

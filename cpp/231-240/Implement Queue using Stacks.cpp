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
        peek();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(s2.empty()) transit();
        return s2.top();
    }
    
    void transit() {
        while(!s1.empty())
        {
            int v = s1.top();
            s1.pop();
            s2.push(v);
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};

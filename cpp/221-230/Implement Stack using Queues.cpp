class Stack {
    
    queue<int> q1;
    queue<int> q2;
    int v;
    
public:
    // Push element x onto stack.
    void push(int x) {
        if(!q1.empty())
            q1.push(x);
        else
            q2.push(x);
        v = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!q1.empty())
        {
            while(!q1.empty())
            {
                int tmp = q1.front();
                if(q1.size() > 1) q2.push(tmp);
                if(q1.size() == 2) v= tmp;
                q1.pop();
            }
        } else {
            while(!q2.empty())
            {
                int tmp = q2.front();
                if(q2.size() > 1) q1.push(tmp);
                if(q2.size() == 2) v= tmp;
                q2.pop();
            }
        }
    }

    // Get the top element.
    int top() {
        return v;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

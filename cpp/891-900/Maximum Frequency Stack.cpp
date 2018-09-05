class FreqStack {
    
    map<int, int> freq;
    map<int, stack<int>> mystack;
    
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        mystack[freq[x]].push(x);
        maxFreq = max(freq[x], maxFreq);
    }
    
    int pop() {
        int retVal = mystack[maxFreq].top();
        mystack[maxFreq].pop();
        freq[retVal]--;
        if (mystack[maxFreq].empty()) {
            maxFreq--;
        }
        return retVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */

class MovingAverage {
    
    queue<int> myqueue;
    int size;
    int sum;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }
    
    double next(int val) {
        if(myqueue.size() < size) {
            myqueue.push(val);
            sum += val;
        } else {
            myqueue.push(val);
            sum += val;
            sum -= myqueue.front();
            myqueue.pop();
        }
        return sum*1.0/myqueue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

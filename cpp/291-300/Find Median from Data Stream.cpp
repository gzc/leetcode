class MedianFinder {
    priority_queue<int, vector<int>, std::less<int>> maximum_heap;
    priority_queue<int, vector<int>, std::greater<int>> minimum_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minimum_heap.push(num);
        
        maximum_heap.push(minimum_heap.top());
        minimum_heap.pop();
        
        if (minimum_heap.size() < maximum_heap.size()) {
            minimum_heap.push(maximum_heap.top());
            maximum_heap.pop();
        }
    }
    
    double findMedian() {
        if (maximum_heap.size() == minimum_heap.size()) {
            return (minimum_heap.top()+maximum_heap.top()) / 2.0;
        }
        return minimum_heap.top();
    }
};

class MedianFinder {
    
    std::priority_queue<double, std::vector<double>, std::less<double> > left;
    std::priority_queue<double, std::vector<double>, std::greater<double> > right;
    
    
public:
    
    // Adds a word into the data structure.
    void addNum(int num) {
        
        int l = left.size();
        int r = right.size();
        double v = num;
        
        if(l == 0 && r == 0) {
            left.push(v);
            return;
        }
        
        if(l == 1 && r == 0) {
            if(left.top() <= num)
                right.push(v);
            else{
                int v = left.top();
                left.pop();
                right.push(v);
                left.push(num);
            }
            return;
        }
        
        double lt = left.top();
        double rt = right.top();
        
        if(l == r)
        {
            if(v >= lt && v <= rt) {
                left.push(v);
            } else if(v <= lt) {
                left.push(v);
            } else {
                right.pop();
                right.push(v);
                left.push(rt);
            }
        } else {
            if(v >= lt) {
                right.push(v);
            } else {
                right.push(lt);
                left.pop();
                left.push(v);
            }
        }
        
        
        
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    double findMedian() {
        int l = left.size();
        int r = right.size();
        
        if(l > r) return left.top();
        return (left.top()+right.top())/2;
    }
};
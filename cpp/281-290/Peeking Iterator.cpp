class PeekingIterator : public Iterator {
    
    int peekele;
    bool peeked;
    
public:
    PeekingIterator(const vector<int>& num) : Iterator(num) {
        // Initialize any member here.
        peeked = false;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(!peeked) {
            peekele = Iterator::next();
            peeked = true;
        }
        return peekele;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(!peeked) return Iterator::next();
        peeked = false;
        return peekele;
    }
    
    bool hasNext() const {
        if(peeked) return true;
        if(Iterator::hasNext()) return true;
        return false;
    }
};
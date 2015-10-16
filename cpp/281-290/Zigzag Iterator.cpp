class ZigzagIterator {
    
    queue<vector<int>::iterator> myqueue;
    set<vector<int>::iterator> dead;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.begin() != v1.end())
            myqueue.push(v1.begin());
        if(v2.begin() != v2.end())
            myqueue.push(v2.begin());
        dead.insert(v1.end());
        dead.insert(v2.end());
    }
    
    int next() {
        vector<int>::iterator it = myqueue.front();
        myqueue.pop();
        int v = *it;
        it++;
        if(dead.count(it) == 0) myqueue.push(it);
        return v;
    }
    
    bool hasNext() {
        return !myqueue.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
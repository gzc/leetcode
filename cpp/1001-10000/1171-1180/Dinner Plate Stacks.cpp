class DinnerPlates {
    
    vector<stack<int>> v;
    int capacity;
    int bestindex;
    
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        bestindex = 0;
    }
    
    void push(int val) {
        for (int i = bestindex; i < v.size(); i++) {
            stack<int>& s = v[i];
            if (s.size() < capacity) {
                s.push(val);
                bestindex = i;
                return;
            }
        }
        stack<int> ss;
        ss.push(val);
        v.emplace_back(ss);
        bestindex = v.size() - 1;
    }
    
    int pop() {
        for (int i = v.size() - 1; i >= 0; i--) {
            stack<int>& s = v[i];
            if (!s.empty()) {
                int ret = s.top();
                s.pop();
                bestindex = min(bestindex, i);
                return ret;
            }
            v.pop_back();
            bestindex = max(0, min(bestindex, (int)v.size()-1));
        }
        return -1;
    }
    
    int popAtStack(int index) {
        stack<int>& s = v[index];
        if (!s.empty()) {
            int ret = s.top();
            s.pop();
            bestindex = min(bestindex, index);
            return ret;
        }
        return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

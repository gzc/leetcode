class MyCalendarTwo {
    vector<pair<int, int>> once;
    vector<pair<int, int>> twice;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for (const pair<int, int>& p : twice)
            if (max(p.first, start) < min(end, p.second)) return false;
        
        for (const pair<int, int>& p : once) {
            if (max(p.first, start) < min(end, p.second)) {
                int duplicateStart = max(p.first, start);
                int duplicateEnd = min(end, p.second);
                twice.push_back({duplicateStart, duplicateEnd});
            }
        }
        
        once.push_back({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

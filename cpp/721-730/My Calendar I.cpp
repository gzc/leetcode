class MyCalendar {
    vector<pair<int, int>> books;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const pair<int, int>& p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
